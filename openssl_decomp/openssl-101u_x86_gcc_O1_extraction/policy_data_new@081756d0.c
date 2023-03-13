
uint * policy_data_new(uint *param_1,ASN1_OBJECT *param_2,int param_3)

{
  ASN1_OBJECT *a;
  uint *ptr;
  _STACK *p_Var1;
  
  if ((param_1 != (uint *)0x0) || (param_2 != (ASN1_OBJECT *)0x0)) {
    if (param_2 == (ASN1_OBJECT *)0x0) {
      a = (ASN1_OBJECT *)0x0;
    }
    else {
      a = OBJ_dup(param_2);
      if (a == (ASN1_OBJECT *)0x0) {
        return (uint *)0x0;
      }
    }
    ptr = (uint *)CRYPTO_malloc(0x10,"pcy_data.c",99);
    if (ptr != (uint *)0x0) {
      p_Var1 = sk_new_null();
      ptr[3] = (uint)p_Var1;
      if (p_Var1 != (_STACK *)0x0) {
        *ptr = ~-(uint)(param_3 == 0) & 0x10;
        if (a == (ASN1_OBJECT *)0x0) {
          ptr[1] = *param_1;
          *param_1 = 0;
        }
        else {
          ptr[1] = (uint)a;
          if (param_1 == (uint *)0x0) {
            ptr[2] = 0;
            return ptr;
          }
        }
        ptr[2] = param_1[1];
        param_1[1] = 0;
        return ptr;
      }
      CRYPTO_free(ptr);
      if (a != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(a);
      }
    }
  }
  return (uint *)0x0;
}

