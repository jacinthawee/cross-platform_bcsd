
ulong X509_subject_name_hash_old(X509 *x)

{
  undefined *puVar1;
  X509 *x_00;
  int iVar2;
  BUF_MEM *pBVar3;
  X509_CINF *pXVar4;
  X509 *x_01;
  X509_CINF *pXVar5;
  X509_NAME *pXVar6;
  ulong uVar7;
  undefined auStack_3c [24];
  X509_CINF *local_24;
  X509 *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pXVar6 = x->cert_info->subject;
  local_14 = *(X509 **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar6,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_3c);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_3c,8);
  x_00 = (X509 *)(*(code *)PTR_EVP_md5_006a70c8)();
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_3c,x_00,0);
  if (iVar2 != 0) {
    pBVar3 = pXVar6->bytes;
    x_00 = (X509 *)pBVar3->data;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_3c,x_00,pBVar3->length);
    if (iVar2 != 0) {
      x_00 = (X509 *)&local_24;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_3c,x_00,0);
      if (iVar2 != 0) {
        uVar7 = ((((uint)local_24 >> 0x10) << 0x18 | ((uint)local_24 >> 0x18) << 0x10) >> 0x10) +
                (((uint)local_24 & 0xff) << 8 | (uint)local_24 >> 8 & 0xff) * 0x10000;
        goto LAB_00575b64;
      }
    }
  }
  uVar7 = 0;
LAB_00575b64:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_3c);
  if (local_14 == *(X509 **)puVar1) {
    return uVar7;
  }
  x_01 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  X509_check_purpose(x_01,-1,0);
  X509_check_purpose(x_00,-1,0);
  uVar7 = (*(code *)PTR_memcmp_006a9ad0)(&x_01->rfc3779_addr,&x_00->rfc3779_addr,0x14);
  if (uVar7 == 0) {
    pXVar4 = x_01->cert_info;
    uVar7 = (pXVar4->enc).modified;
    if (uVar7 == 0) {
      pXVar5 = x_00->cert_info;
      if (((pXVar5->enc).modified == 0) &&
         (uVar7 = (pXVar4->enc).len - (pXVar5->enc).len, uVar7 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00575ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar7 = (*(code *)PTR_memcmp_006a9ad0)((pXVar4->enc).enc,(pXVar5->enc).enc);
        return uVar7;
      }
    }
    else {
      uVar7 = 0;
    }
  }
  return uVar7;
}

