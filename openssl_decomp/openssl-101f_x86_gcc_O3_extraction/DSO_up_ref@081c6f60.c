
int DSO_up_ref(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    CRYPTO_add_lock(&dso->references,1,0x1c,"dso_lib.c",0xbe);
    return 1;
  }
  ERR_put_error(0x25,0x72,0x43,"dso_lib.c",0xba);
  return 0;
}

