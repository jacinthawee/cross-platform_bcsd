
int DSO_up_ref(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&dso->references,1,0x1c,"dso_lib.c",0xb9);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x72,0x43,"dso_lib.c",0xb5);
  return 0;
}

