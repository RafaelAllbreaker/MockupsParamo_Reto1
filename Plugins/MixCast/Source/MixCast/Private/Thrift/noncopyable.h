#ifndef _THRIFT_NONCOPYABLE_H_
#define _THRIFT_NONCOPYABLE_H_ 1
namespace apache {
	namespace thrift {
		class TNonCopyable
		{
		protected:
			// Keep default constructor
#if __cplusplus >= 201103L
			TNonCopyable() = default;
#else
			TNonCopyable() {}
#endif
			// Remove copy constructor and assignment operator
#if __cplusplus >= 201103L
		public:
			TNonCopyable(const TNonCopyable&) = delete;
			TNonCopyable& operator=(const TNonCopyable&) = delete;
#else
		private:
			TNonCopyable(const TNonCopyable&);
			TNonCopyable& operator=(const TNonCopyable&);
#endif
		};
	}
} // apache::thrift
#endif // _THRIFT_NONCOPYABLE_H_