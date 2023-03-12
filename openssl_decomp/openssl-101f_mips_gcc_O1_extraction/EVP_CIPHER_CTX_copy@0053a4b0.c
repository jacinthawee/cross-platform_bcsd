
int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out,EVP_CIPHER_CTX *in)

{
  EVP_CIPHER_CTX *pEVar1;
  int iVar2;
  EVP_CIPHER_CTX *pEVar3;
  void *pvVar4;
  EVP_CIPHER_CTX *pEVar5;
  EVP_CIPHER_CTX *pEVar6;
  EVP_CIPHER *pEVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  ENGINE *pEVar11;
  _func_1091 *p_Var12;
  
  if ((in == (EVP_CIPHER_CTX *)0x0) || (in->cipher == (EVP_CIPHER *)0x0)) {
    ERR_put_error(6,0xa3,0x6f,"evp_enc.c",0x28b);
    return 0;
  }
  if ((in->engine != (ENGINE *)0x0) && (iVar2 = ENGINE_init(in->engine), iVar2 == 0)) {
    ERR_put_error(6,0xa3,0x26,"evp_enc.c",0x292);
    return 0;
  }
  if (out->cipher == (EVP_CIPHER *)0x0) {
LAB_0053a544:
    if (out->cipher_data != (void *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
  }
  else {
    p_Var12 = out->cipher->cleanup;
    if ((p_Var12 != (_func_1091 *)0x0) && (iVar2 = (*p_Var12)(out), iVar2 == 0)) goto LAB_0053a58c;
    if (out->cipher_data != (void *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(out->cipher_data,out->cipher->ctx_size);
      goto LAB_0053a544;
    }
  }
  if (out->engine != (ENGINE *)0x0) {
    ENGINE_finish(out->engine);
  }
  (*(code *)PTR_memset_006aab00)(out,0,0x8c);
LAB_0053a58c:
  pEVar1 = out;
  pEVar6 = in;
  do {
    pEVar5 = pEVar6;
    pEVar3 = pEVar1;
    pEVar11 = pEVar5->engine;
    iVar9 = pEVar5->encrypt;
    iVar2 = pEVar5->buf_len;
    pEVar6 = (EVP_CIPHER_CTX *)pEVar5->oiv;
    pEVar3->cipher = pEVar5->cipher;
    pEVar3->engine = pEVar11;
    pEVar3->encrypt = iVar9;
    pEVar3->buf_len = iVar2;
    pEVar1 = (EVP_CIPHER_CTX *)pEVar3->oiv;
  } while (pEVar6 != (EVP_CIPHER_CTX *)(in->final + 0x14));
  uVar10 = *(undefined4 *)(pEVar5->oiv + 4);
  uVar8 = *(undefined4 *)(pEVar5->oiv + 8);
  *(undefined4 *)pEVar3->oiv = *(undefined4 *)pEVar6;
  *(undefined4 *)(pEVar3->oiv + 4) = uVar10;
  *(undefined4 *)(pEVar3->oiv + 8) = uVar8;
  pEVar7 = in->cipher;
  if ((in->cipher_data != (void *)0x0) && (pEVar7->ctx_size != 0)) {
    pvVar4 = (void *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pEVar7->ctx_size,"evp_enc.c",0x29c);
    out->cipher_data = pvVar4;
    if (pvVar4 == (void *)0x0) {
      ERR_put_error(6,0xa3,0x41,"evp_enc.c",0x29f);
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)(pvVar4,in->cipher_data,in->cipher->ctx_size);
    pEVar7 = in->cipher;
  }
  if ((pEVar7->flags & 0x400) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0053a678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*pEVar7->ctrl)(in,8,0,out);
  return iVar2;
}

