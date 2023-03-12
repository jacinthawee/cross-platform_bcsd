
ulong X509_NAME_hash(X509_NAME *x)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  ASN1_STRING *pAVar4;
  int iVar5;
  int *piVar6;
  ASN1_STRING *b;
  int iVar7;
  int iVar8;
  undefined auStack_84 [24];
  ASN1_STRING AStack_6c;
  int iStack_5c;
  undefined *puStack_58;
  int iStack_54;
  uchar *puStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  uint local_28 [5];
  int local_14;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(x,0);
  puStack_50 = x->canon_enc;
  iStack_54 = x->canon_enclen;
  local_38 = (**(code **)(local_30 + -0x781c))();
  local_34 = 0;
  iVar2 = (**(code **)(local_30 + -0x73dc))(puStack_50,iStack_54,local_28,0);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (((local_28[0] >> 0x10) << 0x18 | (local_28[0] >> 0x18) << 0x10) >> 0x10) +
            ((local_28[0] & 0xff) << 8 | local_28[0] >> 8 & 0xff) * 0x10000;
  }
  if (local_14 == *(int *)puStack_58) {
    return uVar3;
  }
  pcStack_4c = X509_NAME_hash_old;
  iVar2 = local_14;
  (**(code **)(local_30 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)();
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_84,8);
  pAVar4 = (ASN1_STRING *)(*(code *)PTR_EVP_md5_006a81c8)();
  b = (ASN1_STRING *)0x0;
  iVar5 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84);
  if (iVar5 != 0) {
    b = **(ASN1_STRING ***)(iVar2 + 8);
    pAVar4 = (*(ASN1_STRING ***)(iVar2 + 8))[1];
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84);
    if (iVar2 != 0) {
      b = (ASN1_STRING *)0x0;
      pAVar4 = &AStack_6c;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84);
      if (iVar2 != 0) {
        uVar3 = ((((uint)AStack_6c.length >> 0x10) << 0x18 |
                 ((uint)AStack_6c.length >> 0x18) << 0x10) >> 0x10) +
                ((AStack_6c.length & 0xffU) << 8 | (uint)AStack_6c.length >> 8 & 0xff) * 0x10000;
        goto LAB_005796b4;
      }
    }
  }
  uVar3 = 0;
LAB_005796b4:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
  if (iStack_5c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar2 == 0) {
    return 0;
  }
  iVar7 = 0;
  iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
  if (0 < iVar5) {
    do {
      piVar6 = (int *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar7);
      iVar8 = *piVar6;
      iVar5 = ASN1_STRING_cmp(*(ASN1_STRING **)(iVar8 + 4),b);
      if (iVar5 == 0) {
        iVar5 = *(int *)(iVar8 + 0xc);
        if ((*(int *)(iVar5 + 0xc) == 0) || (*(int *)(iVar5 + 4) != 0)) {
          iVar8 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar5,0);
          if (iVar8 < 0) goto LAB_005797cc;
        }
        if ((pAVar4->flags == 0) || (pAVar4->type != 0)) {
          iVar8 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(pAVar4,0);
          if (iVar8 < 0) goto LAB_005797cc;
        }
        if (*(int *)(iVar5 + 0x10) == pAVar4[1].length) {
          iVar5 = (*(code *)PTR_memcmp_006aabd8)(*(undefined4 *)(iVar5 + 0xc),pAVar4->flags);
          if (iVar5 == 0) {
            return (ulong)piVar6;
          }
        }
      }
LAB_005797cc:
      iVar7 = iVar7 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
    } while (iVar7 < iVar5);
  }
  return 0;
}

