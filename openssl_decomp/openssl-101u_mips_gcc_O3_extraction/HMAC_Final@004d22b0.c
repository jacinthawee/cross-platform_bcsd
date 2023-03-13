
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  EVP_MD_CTX *pEVar5;
  undefined4 local_68;
  undefined auStack_64 [64];
  undefined4 *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  if (ctx->md != (EVP_MD *)0x0) {
    pEVar5 = &ctx->md_ctx;
    iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(pEVar5,auStack_64,&local_68);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(pEVar5,&ctx->o_ctx);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(pEVar5,auStack_64,local_68);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(pEVar5,md,len);
          uVar3 = (uint)(iVar2 != 0);
          goto LAB_004d2324;
        }
      }
    }
  }
  uVar3 = 0;
LAB_004d2324:
  if (local_24 == *(undefined4 **)puVar1) {
    return uVar3;
  }
  puVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar4 + 7);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar4 + 0xd);
  iVar2 = (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar4 + 1);
  *puVar4 = 0;
  return iVar2;
}

