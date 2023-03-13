
void SSL_free_part_7(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)((int)param_1 + 0x70) != 0) {
    (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
  }
  CRYPTO_free_ex_data(1,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0xf0));
  iVar3 = *(int *)((int)param_1 + 0x14);
  if (iVar3 != 0) {
    if (iVar3 == *(int *)((int)param_1 + 0x10)) {
      uVar2 = (*(code *)PTR_BIO_pop_006a79c8)();
      iVar3 = *(int *)((int)param_1 + 0x14);
      *(undefined4 *)((int)param_1 + 0x10) = uVar2;
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar3);
    *(undefined4 *)((int)param_1 + 0x14) = 0;
  }
  if (*(int *)((int)param_1 + 0xc) != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)();
  }
  if ((*(int *)((int)param_1 + 0x10) != 0) &&
     (*(int *)((int)param_1 + 0x10) != *(int *)((int)param_1 + 0xc))) {
    (*(code *)PTR_BIO_free_all_006a6e74)();
  }
  if (*(int *)((int)param_1 + 0x3c) != 0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)();
  }
  if (*(int *)((int)param_1 + 0x74) != 0) {
    (*(code *)PTR_sk_free_006a6e80)();
  }
  if (*(int *)((int)param_1 + 0x78) != 0) {
    (*(code *)PTR_sk_free_006a6e80)();
  }
  if (*(int *)((int)param_1 + 0xc0) != 0) {
    ssl_clear_bad_session(param_1);
    SSL_SESSION_free(*(SSL_SESSION **)((int)param_1 + 0xc0));
  }
  if (*(int *)((int)param_1 + 0x80) != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(*(void **)((int)param_1 + 0x80));
    *(undefined4 *)((int)param_1 + 0x80) = 0;
  }
  if (*(int *)((int)param_1 + 0x8c) != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(*(void **)((int)param_1 + 0x8c));
    *(undefined4 *)((int)param_1 + 0x8c) = 0;
  }
  if (*(int *)((int)param_1 + 0x88) != 0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    *(undefined4 *)((int)param_1 + 0x88) = 0;
  }
  if (*(int *)((int)param_1 + 0x94) != 0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    *(undefined4 *)((int)param_1 + 0x94) = 0;
  }
  if (*(int *)((int)param_1 + 0x84) != 0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  *(undefined4 *)((int)param_1 + 0x84) = 0;
  if (*(int *)((int)param_1 + 0x90) != 0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  *(undefined4 *)((int)param_1 + 0x90) = 0;
  if (*(int *)((int)param_1 + 0x98) != 0) {
    ssl_cert_free();
  }
  if (*(void **)((int)param_1 + 0x120) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x120));
  }
  iVar3 = *(int *)((int)param_1 + 0x170);
  if (iVar3 != 0) {
    iVar1 = CRYPTO_add_lock((int *)(iVar3 + 0x60),-1,0xc,"ssl_lib.c",0x795);
    if (iVar1 < 1) {
      SSL_CTX_free_part_6(iVar3);
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
  if (*(int *)((int)param_1 + 0x134) != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)
              (*(int *)((int)param_1 + 0x134),PTR_X509_EXTENSION_free_006a7168);
  }
  if (*(int *)((int)param_1 + 0x130) != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)
              (*(int *)((int)param_1 + 0x130),PTR_OCSP_RESPID_free_006a81e8);
  }
  if (*(void **)((int)param_1 + 0x138) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x138));
  }
  if (*(int *)((int)param_1 + 0xf8) != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(*(int *)((int)param_1 + 0xf8),PTR_X509_NAME_free_006a6ff8);
  }
  if (*(int *)((int)param_1 + 8) != 0) {
    (**(code **)(*(int *)((int)param_1 + 8) + 0xc))(param_1);
  }
  iVar3 = *(int *)((int)param_1 + 0xe4);
  if (iVar3 != 0) {
    iVar1 = CRYPTO_add_lock((int *)(iVar3 + 0x60),-1,0xc,"ssl_lib.c",0x795);
    if (iVar1 < 1) {
      SSL_CTX_free_part_6(iVar3);
    }
  }
  if (*(void **)((int)param_1 + 0x174) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x174));
  }
  if (*(int *)((int)param_1 + 0x17c) != 0) {
    (*(code *)PTR_sk_free_006a6e80)();
  }
  CRYPTO_free(param_1);
  return;
}

