
int DSO_up_ref(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    (*(code *)PTR_CRYPTO_add_lock_006a9080)(&dso->references,1,0x1c,"dso_lib.c",0xbe);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x72,0x43,"dso_lib.c",0xba);
  return 0;
}

