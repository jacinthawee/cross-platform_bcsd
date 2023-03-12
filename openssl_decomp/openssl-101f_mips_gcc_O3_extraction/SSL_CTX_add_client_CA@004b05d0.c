
int SSL_CTX_add_client_CA(SSL_CTX *ctx,X509 *x)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  stack_st_X509_NAME *psVar4;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  if (ctx->client_CA == (stack_st_X509_NAME *)0x0) {
    psVar4 = (stack_st_X509_NAME *)(*(code *)PTR_sk_new_null_006a80a4)(x);
    ctx->client_CA = psVar4;
    if (psVar4 == (stack_st_X509_NAME *)0x0) {
      return 0;
    }
  }
  uVar1 = (*(code *)PTR_X509_get_subject_name_006a8000)(x);
  iVar2 = (*(code *)PTR_X509_NAME_dup_006a823c)(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_sk_push_006a80a8)(ctx->client_CA,iVar2);
  if (iVar3 == 0) {
    (*(code *)PTR_X509_NAME_free_006a80f8)(iVar2);
    return 0;
  }
  return 1;
}

