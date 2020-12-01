const fs = require('fs');
const path = require('path');
const http = require('http');
const zip = require('zip');
const ssl = require('ssl');

const mkdirp = require('../v8/update_helpers/mkdirp');

ssl.loadRootCerts();

const versions = {
    '62.1': {
        tag: 'release-62-1',
        srcUrl: 'https://github.com/unicode-org/icu/releases/download/release-62-1/icu4c-62_1-src.zip',
        dataFilename: 'icudt62l.dat',
    }
}

const currentVersion = '62.1';
const info = versions[currentVersion];

const localFilename = path.resolve(__dirname, path.basename(info.srcUrl));
let buf = null;
let zipFile = null;

if (fs.exists(localFilename)) {
    console.log('read from local file')
    buf = fs.readFile(localFilename)
} else {
    const hc = new http.Client();
    if (process.env.http_proxy)
        hc.proxyAgent = process.env.http_proxy;
    else if (process.env.https_proxy)
        hc.proxyAgent = process.env.https_proxy;

    console.log('start downloading...')
    const resp = hc.get(info.srcUrl);
    console.log('downloaded!')

    buf = resp.readAll();
    fs.writeFile(localFilename, buf);
}

zipFile = zip.open(buf, 'r');

let addedCount = 0
zipFile.namelist().forEach((spath) => {
    const relpath = spath.replace(/^icu\//, '');

    const tpath = path.resolve(__dirname, relpath);

    if (
        (
            relpath.startsWith('source/common')
            || relpath.startsWith('source/data')
            || relpath.startsWith('source/i18n')
            || relpath.startsWith('source/stubdata')
            // || relpath.startsWith('source/tools')
        ) && (
            relpath.endsWith('.cpp')
            || relpath.endsWith('.h')
            || relpath.endsWith('.dat')
        )
    ) {
        if (
            !fs.exists(tpath)
        ) {
            addedCount++;
            console.log('extract file: ', spath);
            mkdirp(path.dirname(tpath));
            zipFile.extract(spath, tpath);
        }
    }
})

console.log();
console.notice(`finished! added ${addedCount} files`);

