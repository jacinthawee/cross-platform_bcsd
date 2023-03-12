
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth_str(ENGINE *e,char *str,int len)

{
  undefined *puVar1;
  undefined *puVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  int *piVar4;
  int iVar5;
  int *unaff_s1;
  code *unaff_s2;
  undefined4 uVar6;
  int iStack_74;
  EVP_PKEY_ASN1_METHOD *pEStack_70;
  EVP_PKEY_ASN1_METHOD **ppEStack_6c;
  int *piStack_68;
  int iStack_64;
  code *pcStack_60;
  int *piStack_5c;
  code *pcStack_58;
  code *pcStack_54;
  undefined *local_40;
  int local_34;
  EVP_PKEY_ASN1_METHOD *local_30;
  int *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pcStack_60 = *(code **)(e + 0x30);
  local_40 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  ppEStack_6c = (EVP_PKEY_ASN1_METHOD **)str;
  if (pcStack_60 != (code *)0x0) {
    unaff_s1 = (int *)len;
    if (len == -1) {
      unaff_s1 = (int *)(*(code *)PTR_strlen_006a9a24)(str);
    }
    len = (int)&local_34;
    ppEStack_6c = (EVP_PKEY_ASN1_METHOD **)0x0;
    unaff_s2 = (code *)(*pcStack_60)(e,0,len,0);
    if (0 < (int)unaff_s2) {
      pcStack_60 = (code *)0x0;
      do {
        len = 0;
        ppEStack_6c = &local_30;
        (**(code **)(e + 0x30))(e,&local_30,0,*(undefined4 *)(local_34 + (int)pcStack_60 * 4));
        pEVar3 = local_30;
        uVar6 = *(undefined4 *)(local_30 + 0xc);
        piVar4 = (int *)(**(code **)(local_40 + -0x53bc))(uVar6);
        if ((unaff_s1 == piVar4) &&
           (ppEStack_6c = (EVP_PKEY_ASN1_METHOD **)str, len = (int)unaff_s1,
           iVar5 = (**(code **)(local_40 + -0x540c))(uVar6), iVar5 == 0)) break;
        pcStack_60 = pcStack_60 + 1;
        pEVar3 = (EVP_PKEY_ASN1_METHOD *)0x0;
      } while (unaff_s2 != pcStack_60);
      goto LAB_0051cff0;
    }
  }
  pEVar3 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_0051cff0:
  if (local_2c == *(int **)puVar2) {
    return pEVar3;
  }
  pcStack_54 = ENGINE_pkey_asn1_find_str;
  piVar4 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_74 = 0;
  pEStack_70 = (EVP_PKEY_ASN1_METHOD *)0x0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_68 = (int *)len;
  piStack_5c = unaff_s1;
  pcStack_58 = unaff_s2;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"tb_asnmth.c",0xec);
  (*(code *)PTR_engine_table_doall_006a8870)(pkey_asn1_meth_table,look_str_cb,&iStack_74);
  if (iStack_74 != 0) {
    *(int *)(iStack_74 + 0x58) = *(int *)(iStack_74 + 0x58) + 1;
  }
  puVar1 = PTR_CRYPTO_lock_006a8144;
  *piVar4 = iStack_74;
  (*(code *)puVar1)(10,0x1e,"tb_asnmth.c",0xf4);
  if (iStack_64 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  return pEStack_70;
}

