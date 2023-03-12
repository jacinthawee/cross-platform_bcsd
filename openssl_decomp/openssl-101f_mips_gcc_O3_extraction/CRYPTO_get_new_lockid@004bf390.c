
int CRYPTO_get_new_lockid(char *name)

{
  void *ptr;
  int iVar1;
  undefined4 uVar2;
  
  if (app_locks == 0) {
    app_locks = (*(code *)PTR_sk_new_null_006a80a4)();
    if (app_locks == 0) {
      uVar2 = 0xd7;
      goto LAB_004bf46c;
    }
  }
  ptr = (void *)(*(code *)PTR_BUF_strdup_006a80dc)(name);
  if (ptr != (void *)0x0) {
    iVar1 = (*(code *)PTR_sk_push_006a80a8)(app_locks,ptr);
    if (iVar1 != 0) {
      return iVar1 + 0x29;
    }
    CRYPTO_free(ptr);
    return 0;
  }
  uVar2 = 0xdc;
LAB_004bf46c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x65,0x41,s_cryptlib_c_0064d554,uVar2);
  return 0;
}

