
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_18 = 0;
  local_14 = *(char **)PTR___stack_chk_guard_006aabf0;
  if (value == (char *)0x0) {
    in_a2 = (stack_st_CONF_VALUE **)&DAT_0000006d;
    uVar5 = 0xa6;
  }
  else {
    local_18 = (*(code *)PTR_BN_new_006a82b4)();
    cVar6 = *value;
    bVar1 = cVar6 == '-';
    if (bVar1) {
      cVar6 = value[1];
      value = value + 1;
    }
    if ((cVar6 == '0') && ((value[1] & 0xdfU) == 0x58)) {
      value = value + 2;
      iVar3 = (*(code *)PTR_BN_hex2bn_006a81f0)(&local_18,value);
    }
    else {
      iVar3 = (*(code *)PTR_BN_dec2bn_006a8f20)(&local_18,value);
    }
    if ((iVar3 == 0) || (value[iVar3] != '\0')) {
      (*(code *)PTR_BN_free_006a811c)();
      in_a2 = (stack_st_CONF_VALUE **)&DAT_00000064;
      uVar5 = 0xb9;
    }
    else {
      if ((bVar1) && (*(int *)(local_18 + 4) != 0)) {
        iVar3 = 0;
        pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)();
        (*(code *)PTR_BN_free_006a811c)(local_18);
        if (pAVar4 != (ASN1_INTEGER *)0x0) {
          pAVar4->type = pAVar4->type | 0x100;
          goto LAB_0058ce04;
        }
      }
      else {
        iVar3 = 0;
        pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)();
        (*(code *)PTR_BN_free_006a811c)(local_18);
        if (pAVar4 != (ASN1_INTEGER *)0x0) goto LAB_0058ce04;
      }
      in_a2 = (stack_st_CONF_VALUE **)&DAT_00000065;
      uVar5 = 0xc2;
    }
  }
  iVar3 = 0x6c;
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6c,in_a2,"v3_utl.c",uVar5);
  pAVar4 = (ASN1_INTEGER *)0x0;
LAB_0058ce04:
  if (local_14 == *(char **)puVar2) {
    return pAVar4;
  }
  name = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 0) {
    return (ASN1_INTEGER *)0x1;
  }
  iVar3 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar3,0);
  if ((iVar3 != 0) &&
     (value_00 = (char *)(*(code *)PTR_BN_bn2dec_006a8f28)(iVar3), value_00 != (char *)0x0)) {
    (*(code *)PTR_BN_free_006a811c)(iVar3);
    pAVar4 = (ASN1_INTEGER *)X509V3_add_value(name,value_00,in_a2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(value_00);
    return pAVar4;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x78,0x41,"v3_utl.c",0x9a);
  (*(code *)PTR_BN_free_006a811c)(iVar3);
  return (ASN1_INTEGER *)0x0;
}

