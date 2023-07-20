#include"Runtime/BattleFirePrefix.h"
namespace Alice{
    struct Delegate {
        Delegate* mNext;
        VOID_VOID_PTR mCallback;
        Delegate():mNext(nullptr),mCallback(nullptr){
        }
        void operator-=(VOID_VOID_PTR inCallback){
            Delegate*current=this;
            while(current!=nullptr)
            {
                if(current->mNext!=nullptr&&current->mNext->mCallback==inCallback){
                    Delegate* delegateToDelete=current->mNext;
                    current->mNext=current->mNext->mNext;
                    delete delegateToDelete;
                    return ;
                }
                current=current->mNext;
            }
        }
        void operator+=(VOID_VOID_PTR inCallback){
            Delegate*current=this;
            Delegate*last=this;
            while(current!=nullptr)
            {
                if(current->mCallback==inCallback){
                    return ;
                }
                current=current->mNext;
                if(current!=nullptr){
                    last=current;
                }
            }
            last->mNext=new Delegate;
            last->mNext->mCallback=inCallback;
        }
        void operator()(void*inArgs){
            Delegate*current=this;
            while(current!=nullptr)
            {
                if(current->mCallback!=nullptr){
                    current->mCallback(inArgs);
                }
                current=current->mNext;
            }
        }
    }
}