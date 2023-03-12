
void EVP_MD_CTX_init(EVP_MD_CTX *ctx)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  ctx->digest = (EVP_MD *)0x0;
  ctx->update = (_func_1088 *)0x0;
  uVar1 = (uint)&ctx->engine & 0xfffffffc;
  do {
    *(undefined4 *)(uVar1 + uVar2) = 0;
    uVar2 = uVar2 + 4;
  } while (uVar2 < ((int)ctx + (0x18 - uVar1) & 0xfffffffc));
  return;
}

