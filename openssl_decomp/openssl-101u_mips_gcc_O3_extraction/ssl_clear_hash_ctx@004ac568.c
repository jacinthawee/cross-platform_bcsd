
void ssl_clear_hash_ctx(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  *param_1 = 0;
  return;
}

