#include"Runtime/BattleFirePrefix.h"
namespace Alice{
    class Object{
    public:
        Object():mReferenceCount(0){}
        int mReferenceCount;
        int retain(){
            return ++mReferenceCount;
        }
        void release(){
            mReferenceCount--;
            if(mReferenceCount==0){
                //delete this
            }
        }
    };
} // namespace Alice
