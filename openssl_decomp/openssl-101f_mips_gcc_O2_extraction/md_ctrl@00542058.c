
int md_ctrl(int param_1,int param_2,undefined4 param_3,EVP_MD *param_4)

{
  int iVar1;
  EVP_MD_CTX *ctx;
  undefined4 uVar2;
  
  ctx = *(EVP_MD_CTX **)(param_1 + 0x20);
  if (param_2 == 0x6f) {
    iVar1 = EVP_DigestInit_ex(ctx,param_4,(ENGINE *)0x0);
    if (iVar1 < 1) {
      return iVar1;
    }
    *(undefined4 *)(param_1 + 0xc) = 1;
    return iVar1;
  }
  if (param_2 < 0x70) {
    if (param_2 == 0xc) {
      iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)param_4->cleanup,ctx);
      if (iVar1 == 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
    if (param_2 == 0x65) {
      (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
      iVar1 = (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)(param_1 + 0x24),0x65,param_3,param_4)
      ;
      (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
      return iVar1;
    }
    if (param_2 == 1) {
      if (*(int *)(param_1 + 0xc) == 0) {
        return 0;
      }
      iVar1 = EVP_DigestInit_ex(ctx,ctx->digest,(ENGINE *)0x0);
      if (iVar1 < 1) {
        return iVar1;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x24);
      param_2 = 1;
      goto LAB_005420b4;
    }
  }
  else {
    if (param_2 == 0x78) {
      param_4->type = (int)ctx;
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
    if (param_2 == 0x94) {
      if (*(int *)(param_1 + 0xc) != 0) {
        *(EVP_MD **)(param_1 + 0x20) = param_4;
        return 1;
      }
      return 0;
    }
    if (param_2 == 0x70) {
      if (*(int *)(param_1 + 0xc) != 0) {
        param_4->type = (int)ctx->digest;
        return 1;
      }
      return 0;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x24);
LAB_005420b4:
                    /* WARNING: Could not recover jumptable at 0x005420c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_BIO_ctrl_006a7f18)(uVar2,param_2,param_3,param_4);
  return iVar1;
}

