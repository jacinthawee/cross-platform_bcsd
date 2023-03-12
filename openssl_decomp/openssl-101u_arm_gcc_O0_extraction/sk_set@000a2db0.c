
void * sk_set(_STACK *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  
  pvVar1 = (void *)((uint)param_2 >> 0x1f);
  if (param_1 == (_STACK *)0x0) {
    pvVar1 = (void *)0x1;
  }
  if (pvVar1 != (void *)0x0) {
    return (void *)0x0;
  }
  if (param_2 < param_1->num) {
    param_1->data[param_2] = (char *)param_3;
    pvVar1 = param_3;
  }
  return pvVar1;
}

