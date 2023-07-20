#include"Runtime/Base/ScriptableObject.h"
namespace Alice{
    namespace UI{
        class UIBehaviour : public ScriptableObject{
        protected:
            virtual void Awake(){}
            virtual void OnEnable(){}
            virtual void Start(){}
            virtual void OnDisable(){}
            virtual void OnDestroy(){}
            virtual bool IsActive(){return mIsActiveAndEnabled;}
            virtual void OnRectTransformDimensionsChange(){}
            virtual void OnBeforeTransformParentChanged(){}
            virtual void OnTransformParentChanged(){}
            virtual void OnDidApplyAnimationProperties(){}
            virtual void OnCanvasGroupChanged(){}
            virtual void OnCanvasHierarchyChanged(){}
        };
    } // namespace UI
}