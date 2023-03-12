
int sk_set_cmp_func(void *param_1,void *param_2)

{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)param_1 + 0x10);
  if (pvVar1 != param_2) {
    *(undefined4 *)((int)param_1 + 8) = 0;
  }
  *(void **)((int)param_1 + 0x10) = param_2;
  return (int)pvVar1;
}

