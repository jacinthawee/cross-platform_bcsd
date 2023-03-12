
ulong X509_issuer_name_hash_old(X509 *a)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  BUF_MEM *pBVar4;
  X509_NAME *pXVar5;
  ulong uVar6;
  undefined auStack_3c [24];
  uint local_24 [4];
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pXVar5 = a->cert_info->issuer;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar5,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_3c,8);
  uVar2 = (*(code *)PTR_EVP_md5_006a81c8)();
  iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_3c,uVar2,0);
  if (iVar3 != 0) {
    pBVar4 = pXVar5->bytes;
    iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_3c,pBVar4->data,pBVar4->length);
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_3c,local_24,0);
      if (iVar3 != 0) {
        uVar6 = (((local_24[0] >> 0x10) << 0x18 | (local_24[0] >> 0x18) << 0x10) >> 0x10) +
                ((local_24[0] & 0xff) << 8 | local_24[0] >> 8 & 0xff) * 0x10000;
        goto LAB_0057916c;
      }
    }
  }
  uVar6 = 0;
LAB_0057916c:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_3c);
  if (local_14 == *(int **)puVar1) {
    return uVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ulong *)(*local_14 + 0x14);
}

