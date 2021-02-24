
#include "mutex.h"
#include <exlib/include/fiber.h>

namespace v8 {
namespace base {

    Mutex::Mutex()
    {
        native_handle_ = new exlib::Locker(false);
    }

    Mutex::~Mutex()
    {
        delete native_handle_;
    }

    void Mutex::Lock()
    {
        native_handle_->lock();
    }

    void Mutex::Unlock()
    {
        native_handle_->unlock();
    }

    bool Mutex::TryLock()
    {
        return native_handle_->trylock();
    }

    RecursiveMutex::RecursiveMutex()
    {
        native_handle_ = new exlib::Locker(true);
    }

    RecursiveMutex::~RecursiveMutex()
    {
        delete native_handle_;
    }

    void RecursiveMutex::Lock()
    {
        native_handle_->lock();
    }

    void RecursiveMutex::Unlock()
    {
        native_handle_->unlock();
    }

    bool RecursiveMutex::TryLock()
    {
        return native_handle_->trylock();
    }

    #if V8_OS_POSIX

    SharedMutex::SharedMutex() { pthread_rwlock_init(&native_handle_, nullptr); }

    SharedMutex::~SharedMutex() {
        int result = pthread_rwlock_destroy(&native_handle_);
        DCHECK_EQ(0, result);
        USE(result);
    }

    void SharedMutex::LockShared() {
        int result = pthread_rwlock_rdlock(&native_handle_);
        DCHECK_EQ(0, result);
        USE(result);
    }

    void SharedMutex::LockExclusive() {
        int result = pthread_rwlock_wrlock(&native_handle_);
        DCHECK_EQ(0, result);
        USE(result);
    }

    void SharedMutex::UnlockShared() {
        int result = pthread_rwlock_unlock(&native_handle_);
        DCHECK_EQ(0, result);
        USE(result);
    }

    void SharedMutex::UnlockExclusive() {
        // Same code as {UnlockShared} on POSIX.
        UnlockShared();
    }

    bool SharedMutex::TryLockShared() {
        return pthread_rwlock_tryrdlock(&native_handle_) == 0;
    }

    bool SharedMutex::TryLockExclusive() {
        return pthread_rwlock_trywrlock(&native_handle_) == 0;
    }

    #elif V8_OS_WIN

    SharedMutex::SharedMutex() : native_handle_(SRWLOCK_INIT) {}

    SharedMutex::~SharedMutex() {}

    void SharedMutex::LockShared() { AcquireSRWLockShared(&native_handle_); }

    void SharedMutex::LockExclusive() { AcquireSRWLockExclusive(&native_handle_); }

    void SharedMutex::UnlockShared() { ReleaseSRWLockShared(&native_handle_); }

    void SharedMutex::UnlockExclusive() {
        ReleaseSRWLockExclusive(&native_handle_);
    }

    bool SharedMutex::TryLockShared() {
        return TryAcquireSRWLockShared(&native_handle_);
    }

    bool SharedMutex::TryLockExclusive() {
        return TryAcquireSRWLockExclusive(&native_handle_);
    }
    #endif
}
} // namespace v8::base
