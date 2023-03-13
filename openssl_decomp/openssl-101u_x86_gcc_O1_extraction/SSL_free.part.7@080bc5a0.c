
void __regparm3 SSL_free_part_7(void *param_1)

{
  int iVar1;
  BIO *pBVar2;
  
  if (*(X509_VERIFY_PARAM **)((int)param_1 + 0x70) != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(*(X509_VERIFY_PARAM **)((int)param_1 + 0x70));
  }
  CRYPTO_free_ex_data(1,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0xf0));
  pBVar2 = *(BIO **)((int)param_1 + 0x14);
  if (pBVar2 != (BIO *)0x0) {
    if (pBVar2 == *(BIO **)((int)param_1 + 0x10)) {
      pBVar2 = BIO_pop(pBVar2);
      *(BIO **)((int)param_1 + 0x10) = pBVar2;
      pBVar2 = *(BIO **)((int)param_1 + 0x14);
    }
    BIO_free(pBVar2);
    *(undefined4 *)((int)param_1 + 0x14) = 0;
  }
  if (*(BIO **)((int)param_1 + 0xc) != (BIO *)0x0) {
    BIO_free_all(*(BIO **)((int)param_1 + 0xc));
  }
  pBVar2 = *(BIO **)((int)param_1 + 0x10);
  if ((pBVar2 != (BIO *)0x0) && (pBVar2 != *(BIO **)((int)param_1 + 0xc))) {
    BIO_free_all(pBVar2);
  }
  if (*(BUF_MEM **)((int)param_1 + 0x3c) != (BUF_MEM *)0x0) {
    BUF_MEM_free(*(BUF_MEM **)((int)param_1 + 0x3c));
  }
  if (*(_STACK **)((int)param_1 + 0x74) != (_STACK *)0x0) {
    sk_free(*(_STACK **)((int)param_1 + 0x74));
  }
  if (*(_STACK **)((int)param_1 + 0x78) != (_STACK *)0x0) {
    sk_free(*(_STACK **)((int)param_1 + 0x78));
  }
  if (*(int *)((int)param_1 + 0xc0) != 0) {
    ssl_clear_bad_session(param_1);
    SSL_SESSION_free(*(SSL_SESSION **)((int)param_1 + 0xc0));
  }
  if (*(EVP_CIPHER_CTX **)((int)param_1 + 0x80) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(*(EVP_CIPHER_CTX **)((int)param_1 + 0x80));
    CRYPTO_free(*(void **)((int)param_1 + 0x80));
    *(undefined4 *)((int)param_1 + 0x80) = 0;
  }
  if (*(EVP_CIPHER_CTX **)((int)param_1 + 0x8c) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(*(EVP_CIPHER_CTX **)((int)param_1 + 0x8c));
    CRYPTO_free(*(void **)((int)param_1 + 0x8c));
    *(undefined4 *)((int)param_1 + 0x8c) = 0;
  }
  if (*(COMP_CTX **)((int)param_1 + 0x88) != (COMP_CTX *)0x0) {
    COMP_CTX_free(*(COMP_CTX **)((int)param_1 + 0x88));
    *(undefined4 *)((int)param_1 + 0x88) = 0;
  }
  if (*(COMP_CTX **)((int)param_1 + 0x94) != (COMP_CTX *)0x0) {
    COMP_CTX_free(*(COMP_CTX **)((int)param_1 + 0x94));
    *(undefined4 *)((int)param_1 + 0x94) = 0;
  }
  if (*(EVP_MD_CTX **)((int)param_1 + 0x84) != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)param_1 + 0x84));
  }
  *(undefined4 *)((int)param_1 + 0x84) = 0;
  if (*(EVP_MD_CTX **)((int)param_1 + 0x90) != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)param_1 + 0x90));
  }
  *(undefined4 *)((int)param_1 + 0x90) = 0;
  if (*(int *)((int)param_1 + 0x98) != 0) {
    ssl_cert_free(*(int *)((int)param_1 + 0x98));
  }
  if (*(void **)((int)param_1 + 0x120) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x120));
  }
  if (*(int *)((int)param_1 + 0x170) != 0) {
    iVar1 = CRYPTO_add_lock((int *)(*(int *)((int)param_1 + 0x170) + 0x60),-1,0xc,"ssl_lib.c",0x795)
    ;
    if (iVar1 < 1) {
      SSL_CTX_free_part_6();
    }
  }
  if (*(void **)((int)param_1 + 0x148) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x148));
  }
  if (*(void **)((int)param_1 + 0x150) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x150));
  }
  if (*(void **)((int)param_1 + 0x154) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x154));
  }
  if (*(_STACK **)((int)param_1 + 0x134) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)((int)param_1 + 0x134),X509_EXTENSION_free);
  }
  if (*(_STACK **)((int)param_1 + 0x130) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)((int)param_1 + 0x130),OCSP_RESPID_free);
  }
  if (*(void **)((int)param_1 + 0x138) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x138));
  }
  if (*(_STACK **)((int)param_1 + 0xf8) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)((int)param_1 + 0xf8),X509_NAME_free);
  }
  if (*(int *)((int)param_1 + 8) != 0) {
    (**(code **)(*(int *)((int)param_1 + 8) + 0xc))(param_1);
  }
  if (*(int *)((int)param_1 + 0xe4) != 0) {
    iVar1 = CRYPTO_add_lock((int *)(*(int *)((int)param_1 + 0xe4) + 0x60),-1,0xc,"ssl_lib.c",0x795);
    if (iVar1 < 1) {
      SSL_CTX_free_part_6();
    }
  }
  if (*(void **)((int)param_1 + 0x174) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x174));
  }
  if (*(_STACK **)((int)param_1 + 0x17c) != (_STACK *)0x0) {
    sk_free(*(_STACK **)((int)param_1 + 0x17c));
  }
  CRYPTO_free(param_1);
  return;
}

