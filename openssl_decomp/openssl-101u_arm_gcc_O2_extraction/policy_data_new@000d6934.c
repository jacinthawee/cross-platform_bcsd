
undefined4 * policy_data_new(undefined4 *param_1,ASN1_OBJECT *param_2,int param_3)

{
  undefined4 *ptr;
  _STACK *p_Var1;
  undefined4 uVar2;
  
  if ((param_1 != (undefined4 *)0x0 || param_2 != (ASN1_OBJECT *)0x0) &&
     (((param_2 == (ASN1_OBJECT *)0x0 || (param_2 = OBJ_dup(param_2), param_2 != (ASN1_OBJECT *)0x0)
       ) && (ptr = (undefined4 *)CRYPTO_malloc(0x10,"pcy_data.c",99), ptr != (undefined4 *)0x0)))) {
    p_Var1 = sk_new_null();
    ptr[3] = p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      if (param_3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0x10;
      }
      *ptr = uVar2;
      if (param_2 == (ASN1_OBJECT *)0x0) {
        ptr[1] = *param_1;
        *param_1 = 0;
      }
      else {
        ptr[1] = param_2;
        if (param_1 == (undefined4 *)0x0) {
          ptr[2] = 0;
          return ptr;
        }
      }
      ptr[2] = param_1[1];
      param_1[1] = 0;
      return ptr;
    }
    CRYPTO_free(ptr);
    if (param_2 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(param_2);
      return (undefined4 *)0x0;
    }
  }
  return (undefined4 *)0x0;
}

