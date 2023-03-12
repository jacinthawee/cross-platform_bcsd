
undefined4 ssl3_new(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x424,"s3_lib.c",0xb80);
  if (iVar2 != 0) {
    (*(code *)PTR_memset_006aab00)(iVar2,0,0x424);
    *(undefined *)(iVar2 + 0x128) = 0;
    *(undefined *)(iVar2 + 0x129) = 0;
    *(undefined *)(iVar2 + 0x12a) = 0;
    *(undefined *)(iVar2 + 299) = 0;
    *(undefined *)(iVar2 + 300) = 0;
    *(undefined *)(iVar2 + 0x12d) = 0;
    *(undefined *)(iVar2 + 0x12e) = 0;
    *(undefined *)(iVar2 + 0x12f) = 0;
    *(undefined *)(iVar2 + 0x14c) = 0;
    *(undefined *)(iVar2 + 0x14d) = 0;
    *(undefined *)(iVar2 + 0x14e) = 0;
    *(undefined *)(iVar2 + 0x14f) = 0;
    *(undefined *)(iVar2 + 0x150) = 0;
    *(undefined *)(iVar2 + 0x151) = 0;
    *(undefined *)(iVar2 + 0x152) = 0;
    *(undefined *)(iVar2 + 0x153) = 0;
    puVar1 = PTR_SSL_SRP_CTX_init_006a91e0;
    *(int *)(param_1 + 0x58) = iVar2;
    (*(code *)puVar1)(param_1);
    (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
    return 1;
  }
  return 0;
}

