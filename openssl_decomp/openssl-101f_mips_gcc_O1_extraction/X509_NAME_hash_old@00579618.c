
ulong X509_NAME_hash_old(X509_NAME *x)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  ASN1_STRING *b;
  int iVar6;
  ulong uVar7;
  int iVar8;
  undefined auStack_3c [24];
  uint local_24 [4];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(x,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_3c,8);
  puVar2 = (uint *)(*(code *)PTR_EVP_md5_006a81c8)();
  b = (ASN1_STRING *)0x0;
  iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_3c);
  if (iVar3 != 0) {
    b = (ASN1_STRING *)x->bytes->length;
    puVar2 = (uint *)x->bytes->data;
    iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_3c);
    if (iVar3 != 0) {
      b = (ASN1_STRING *)0x0;
      puVar2 = local_24;
      iVar3 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_3c);
      if (iVar3 != 0) {
        uVar7 = (((local_24[0] >> 0x10) << 0x18 | (local_24[0] >> 0x18) << 0x10) >> 0x10) +
                ((local_24[0] & 0xff) << 8 | local_24[0] >> 8 & 0xff) * 0x10000;
        goto LAB_005796b4;
      }
    }
  }
  uVar7 = 0;
LAB_005796b4:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_3c);
  if (local_14 == *(int *)puVar1) {
    return uVar7;
  }
  iVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 0) {
    return 0;
  }
  iVar6 = 0;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
  if (0 < iVar4) {
    do {
      piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(iVar3,iVar6);
      iVar8 = *piVar5;
      iVar4 = ASN1_STRING_cmp(*(ASN1_STRING **)(iVar8 + 4),b);
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar8 + 0xc);
        if ((*(int *)(iVar4 + 0xc) == 0) || (*(int *)(iVar4 + 4) != 0)) {
          iVar8 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar4,0);
          if (iVar8 < 0) goto LAB_005797cc;
        }
        if ((puVar2[3] == 0) || (puVar2[1] != 0)) {
          iVar8 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(puVar2,0);
          if (iVar8 < 0) goto LAB_005797cc;
        }
        if (*(uint *)(iVar4 + 0x10) == puVar2[4]) {
          iVar4 = (*(code *)PTR_memcmp_006aabd8)(*(undefined4 *)(iVar4 + 0xc),puVar2[3]);
          if (iVar4 == 0) {
            return (ulong)piVar5;
          }
        }
      }
LAB_005797cc:
      iVar6 = iVar6 + 1;
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
    } while (iVar6 < iVar4);
  }
  return 0;
}

