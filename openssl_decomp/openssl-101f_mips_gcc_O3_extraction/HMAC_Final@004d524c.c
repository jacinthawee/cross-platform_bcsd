
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  EVP_MD_CTX *pEVar4;
  undefined4 local_68;
  undefined auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pEVar4 = &ctx->md_ctx;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(pEVar4,auStack_64,&local_68);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(pEVar4,&ctx->o_ctx);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(pEVar4,auStack_64,local_68);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(pEVar4,md,len);
        uVar3 = (uint)(iVar2 != 0);
        goto LAB_004d52bc;
      }
    }
  }
  uVar3 = 0;
LAB_004d52bc:
  if (local_24 == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(iVar2 + 0x1c);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(iVar2 + 0x34);
                    /* WARNING: Could not recover jumptable at 0x004d5398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(iVar2 + 4);
  return iVar2;
}

