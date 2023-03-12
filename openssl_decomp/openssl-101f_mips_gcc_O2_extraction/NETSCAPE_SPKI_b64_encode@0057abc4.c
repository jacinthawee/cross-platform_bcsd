
char * NETSCAPE_SPKI_b64_encode(NETSCAPE_SPKI *x)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int local_28;
  char *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(char **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_i2d_NETSCAPE_SPKI_006a9fec)(x,0);
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"x509spki.c",0x6e);
  pcVar4 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 << 1,"x509spki.c",0x6f);
  if ((iVar3 == 0) || (pcVar4 == (char *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x82,0x41,"x509spki.c",0x71);
    pcVar4 = (char *)0x0;
  }
  else {
    local_28 = iVar3;
    (*(code *)PTR_i2d_NETSCAPE_SPKI_006a9fec)(x,&local_28);
    (*(code *)PTR_EVP_EncodeBlock_006a9c14)(pcVar4,iVar3,iVar2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
  }
  if (local_24 == *(char **)puVar1) {
    return pcVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return local_24;
}

