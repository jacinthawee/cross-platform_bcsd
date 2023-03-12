
int CRYPTO_get_new_lockid(char *name)

{
  void *ptr;
  int iVar1;
  undefined4 uVar2;
  
  if (app_locks == 0) {
    app_locks = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (app_locks == 0) {
      uVar2 = 0xdd;
      goto LAB_004bc30c;
    }
  }
  ptr = (void *)(*(code *)PTR_BUF_strdup_006a6fdc)(name);
  if (ptr != (void *)0x0) {
    iVar1 = (*(code *)PTR_sk_push_006a6fa8)(app_locks,ptr);
    if (iVar1 != 0) {
      return iVar1 + 0x29;
    }
    CRYPTO_free(ptr);
    return 0;
  }
  uVar2 = 0xe1;
LAB_004bc30c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x65,0x41,s_cryptlib_c_0064cbb4,uVar2);
  return 0;
}

