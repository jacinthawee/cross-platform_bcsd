
ulong X509_subject_name_hash_old(X509 *x)

{
  undefined *puVar1;
  X509 *x_00;
  int iVar2;
  BUF_MEM *pBVar3;
  X509 *x_01;
  X509_NAME *pXVar4;
  ulong uVar5;
  undefined auStack_3c [24];
  X509_CINF *local_24;
  X509 *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pXVar4 = x->cert_info->subject;
  local_14 = *(X509 **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar4,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_3c,8);
  x_00 = (X509 *)(*(code *)PTR_EVP_md5_006a81c8)();
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_3c,x_00,0);
  if (iVar2 != 0) {
    pBVar3 = pXVar4->bytes;
    x_00 = (X509 *)pBVar3->data;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_3c,x_00,pBVar3->length);
    if (iVar2 != 0) {
      x_00 = (X509 *)&local_24;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_3c,x_00,0);
      if (iVar2 != 0) {
        uVar5 = ((((uint)local_24 >> 0x10) << 0x18 | ((uint)local_24 >> 0x18) << 0x10) >> 0x10) +
                (((uint)local_24 & 0xff) << 8 | (uint)local_24 >> 8 & 0xff) * 0x10000;
        goto LAB_00579384;
      }
    }
  }
  uVar5 = 0;
LAB_00579384:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_3c);
  if (local_14 == *(X509 **)puVar1) {
    return uVar5;
  }
  x_01 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  X509_check_purpose(x_01,-1,0);
  X509_check_purpose(x_00,-1,0);
                    /* WARNING: Could not recover jumptable at 0x00579480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_memcmp_006aabd8)(&x_01->rfc3779_addr,&x_00->rfc3779_addr,0x14);
  return uVar5;
}

