
undefined4 * ecdsa_data_dup(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"ecs_lib.c",0x79);
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2a,100,0x41,"ecs_lib.c",0x7c);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    if (default_ECDSA_method == (ECDSA_METHOD *)0x0) {
      default_ECDSA_method = ECDSA_OpenSSL();
    }
    puVar1 = PTR_ENGINE_get_default_ECDSA_006aa86c;
    puVar2[3] = default_ECDSA_method;
    puVar2[1] = 0;
    iVar3 = (*(code *)puVar1)();
    puVar2[1] = iVar3;
    if (iVar3 == 0) {
      iVar3 = puVar2[3];
    }
    else {
      iVar3 = (*(code *)PTR_ENGINE_get_ECDSA_006aa870)(iVar3);
      puVar2[3] = iVar3;
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2a,100,0x26,"ecs_lib.c",0x8c);
        (*(code *)PTR_ENGINE_finish_006a80c4)(puVar2[1]);
        (*(code *)PTR_CRYPTO_free_006a7f88)(puVar2);
        return (undefined4 *)0x0;
      }
    }
    puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
    puVar2[2] = *(undefined4 *)(iVar3 + 0x10);
    (*(code *)puVar1)(0xc,puVar2,puVar2 + 4);
  }
  return puVar2;
}

