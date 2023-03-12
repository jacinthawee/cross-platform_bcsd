
char * NETSCAPE_SPKI_b64_encode(NETSCAPE_SPKI *x)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int local_28;
  char *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(char **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_i2d_NETSCAPE_SPKI_006a8ed0)(x,0);
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"x509spki.c",0x70);
  pcVar4 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 << 1,"x509spki.c",0x71);
  if ((iVar3 == 0) || (pcVar4 == (char *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x82,0x41,"x509spki.c",0x73);
    pcVar4 = (char *)0x0;
  }
  else {
    local_28 = iVar3;
    (*(code *)PTR_i2d_NETSCAPE_SPKI_006a8ed0)(x,&local_28);
    (*(code *)PTR_EVP_EncodeBlock_006a8af8)(pcVar4,iVar3,iVar2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
  }
  if (local_24 == *(char **)puVar1) {
    return pcVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return local_24;
}

