
int ssl_give_srp_client_pwd_cb(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puStack_24;
  undefined4 local_1c;
  char *local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x401,"s_client.c",0x1e9);
  puVar6 = &local_1c;
  local_1c = *param_2;
  uVar5 = 0;
  pcVar4 = (char *)0x400;
  local_18 = "SRP user";
  iVar3 = password_callback(iVar2,0x400,0);
  if (iVar3 < 0) {
    pcVar4 = "Can\'t read Password\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"Can\'t read Password\n")
    ;
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    iVar2 = 0;
  }
  else {
    *(undefined *)(iVar2 + iVar3) = 0;
  }
  if (local_14 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (c_quiet == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"Protocols advertised by server: ");
      uVar7 = 0;
      while( true ) {
        (*(code *)PTR_BIO_write_006a7f14)
                  (bio_c_out,(int)puVar6 + uVar7 + 1,*(byte *)((int)puVar6 + uVar7));
        uVar7 = uVar7 + *(byte *)((int)puVar6 + uVar7) + 1;
        if (0x6afedf < uVar7) break;
        if (uVar7 != 0) {
          (*(code *)PTR_BIO_write_006a7f14)(bio_c_out,", ",2);
        }
      }
      (*(code *)PTR_BIO_write_006a7f14)(bio_c_out,"\n",1);
    }
    uVar5 = (*(code *)PTR_SSL_select_next_proto_006a8a50)
                      (pcVar4,uVar5,puVar6,&_gp,*puStack_24,*(undefined2 *)(puStack_24 + 1));
    puStack_24[2] = uVar5;
    return 0;
  }
  return iVar2;
}

