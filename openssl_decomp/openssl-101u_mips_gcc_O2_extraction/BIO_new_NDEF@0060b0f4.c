
BIO * BIO_new_NDEF(BIO *out,ASN1_VALUE *val,ASN1_ITEM *it)

{
  undefined *puVar1;
  undefined *puVar2;
  ASN1_VALUE **ppAVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  ASN1_VALUE *pAVar6;
  int iVar7;
  int *piVar8;
  void *pvVar9;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  BIO *local_2c;
  ASN1_VALUE *local_28;
  int *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pvVar9 = it->funcs;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_34 = val;
  if ((pvVar9 == (void *)0x0) || (*(int *)((int)pvVar9 + 0x10) == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd0,0xca,"bio_ndef.c",0x6a);
    pBVar5 = (BIO *)0x0;
  }
  else {
    ppAVar3 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"bio_ndef.c",0x6d);
    pBVar4 = BIO_f_asn1();
    pBVar5 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(pBVar4);
    pAVar6 = (ASN1_VALUE *)(*(code *)PTR_BIO_push_006a74c4)(pBVar5,out);
    if (ppAVar3 == (ASN1_VALUE **)0x0) {
      if (pBVar5 == (BIO *)0x0) {
        pBVar5 = (BIO *)0x0;
      }
      else {
        (*(code *)PTR_BIO_free_006a6e70)(pBVar5);
        pBVar5 = (BIO *)0x0;
      }
    }
    else {
      if (pBVar5 != (BIO *)0x0) {
        if (pAVar6 != (ASN1_VALUE *)0x0) {
          BIO_asn1_set_prefix(pBVar5,ndef_prefix,ndef_prefix_free);
          BIO_asn1_set_suffix(pBVar5,ndef_suffix,ndef_suffix_free);
          local_2c = (BIO *)0x0;
          local_28 = (ASN1_VALUE *)0x0;
          local_30 = pAVar6;
          iVar7 = (**(code **)((int)pvVar9 + 0x10))(10,&local_34,it,&local_30);
          puVar1 = PTR_BIO_ctrl_006a6e18;
          if (0 < iVar7) {
            ppAVar3[1] = (ASN1_VALUE *)it;
            ppAVar3[2] = (ASN1_VALUE *)local_2c;
            *ppAVar3 = local_34;
            ppAVar3[4] = local_28;
            ppAVar3[3] = pAVar6;
            (*(code *)puVar1)(pBVar5,0x99,0,ppAVar3);
            pBVar5 = local_2c;
            goto LAB_0060b240;
          }
        }
        (*(code *)PTR_BIO_free_006a6e70)(pBVar5);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAVar3);
      pBVar5 = (BIO *)0x0;
    }
  }
LAB_0060b240:
  if (local_24 != *(int **)puVar2) {
    piVar8 = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (*piVar8 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (piVar8[1] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0060b37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pBVar5 = (BIO *)(*(code *)PTR_CRYPTO_free_006a6e88)(piVar8);
    return pBVar5;
  }
  return pBVar5;
}

