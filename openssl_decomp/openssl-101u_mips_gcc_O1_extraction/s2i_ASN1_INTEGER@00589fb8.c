
ASN1_INTEGER * s2i_ASN1_INTEGER(X509V3_EXT_METHOD *meth,char *value)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  ASN1_INTEGER *pAVar4;
  undefined4 uVar5;
  char *value_00;
  char cVar6;
  char *name;
  stack_st_CONF_VALUE **in_a2;
  int local_18;
  char *local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_18 = 0;
  local_14 = *(char **)PTR___stack_chk_guard_006a9ae8;
  if (value == (char *)0x0) {
    in_a2 = (stack_st_CONF_VALUE **)&DAT_0000006d;
    uVar5 = 0xb6;
  }
  else {
    local_18 = (*(code *)PTR_BN_new_006a71b4)();
    cVar6 = *value;
    bVar1 = cVar6 == '-';
    if (bVar1) {
      cVar6 = value[1];
      value = value + 1;
    }
    if ((cVar6 == '0') && ((value[1] & 0xdfU) == 0x58)) {
      value = value + 2;
      iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_18,value);
    }
    else {
      iVar3 = (*(code *)PTR_BN_dec2bn_006a7e30)(&local_18,value);
    }
    if ((iVar3 == 0) || (value[iVar3] != '\0')) {
      (*(code *)PTR_BN_free_006a701c)();
      in_a2 = (stack_st_CONF_VALUE **)&DAT_00000064;
      uVar5 = 0xcd;
    }
    else {
      if ((bVar1) && (*(int *)(local_18 + 4) != 0)) {
        iVar3 = 0;
        pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)();
        (*(code *)PTR_BN_free_006a701c)(local_18);
        if (pAVar4 != (ASN1_INTEGER *)0x0) {
          pAVar4->type = pAVar4->type | 0x100;
          goto LAB_0058a094;
        }
      }
      else {
        iVar3 = 0;
        pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)();
        (*(code *)PTR_BN_free_006a701c)(local_18);
        if (pAVar4 != (ASN1_INTEGER *)0x0) goto LAB_0058a094;
      }
      in_a2 = (stack_st_CONF_VALUE **)&DAT_00000065;
      uVar5 = 0xd8;
    }
  }
  iVar3 = 0x6c;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6c,in_a2,"v3_utl.c",uVar5);
  pAVar4 = (ASN1_INTEGER *)0x0;
LAB_0058a094:
  if (local_14 == *(char **)puVar2) {
    return pAVar4;
  }
  name = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar3 == 0) {
    return (ASN1_INTEGER *)0x1;
  }
  iVar3 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar3,0);
  if ((iVar3 != 0) &&
     (value_00 = (char *)(*(code *)PTR_BN_bn2dec_006a7e38)(iVar3), value_00 != (char *)0x0)) {
    (*(code *)PTR_BN_free_006a701c)(iVar3);
    pAVar4 = (ASN1_INTEGER *)X509V3_add_value(name,value_00,in_a2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(value_00);
    return pAVar4;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x78,0x41,"v3_utl.c",0xaa);
  (*(code *)PTR_BN_free_006a701c)(iVar3);
  return (ASN1_INTEGER *)0x0;
}

