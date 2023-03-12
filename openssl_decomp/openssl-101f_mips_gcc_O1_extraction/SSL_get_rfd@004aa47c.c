
int SSL_get_rfd(SSL *s)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  code *pcStack_2c;
  undefined *local_18;
  int local_10;
  int local_c;
  
  puStack_30 = PTR___stack_chk_guard_006aabf0;
  local_10 = -1;
  local_18 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BIO_find_type_006a943c)(s->rbio,0x100);
  if (iVar2 != 0) {
    (**(code **)(local_18 + -0x7fc8))(iVar2,0x69,0,&local_10);
  }
  if (local_c == *(int *)puStack_30) {
    return local_10;
  }
  pcStack_2c = SSL_get_wfd;
  iVar2 = local_c;
  (**(code **)(local_18 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar6 = 0x100;
  iStack_38 = -1;
  iStack_34 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BIO_find_type_006a943c)(*(undefined4 *)(iVar2 + 0x10),0x100);
  if (iVar2 != 0) {
    uVar6 = 0x69;
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x69,0,&iStack_38);
  }
  if (iStack_34 != *(int *)puVar1) {
    iVar2 = iStack_34;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar3 = (*(code *)PTR_BIO_s_socket_006a9440)();
    iVar4 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
    if (iVar4 != 0) {
      (*(code *)PTR_BIO_int_ctrl_006a8948)(iVar4,0x68,0,uVar6);
      iVar5 = *(int *)(iVar2 + 0x14);
      if ((iVar5 != 0) && (iVar5 == *(int *)(iVar2 + 0x10))) {
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar5 + 0x24);
        *(undefined4 *)(iVar5 + 0x24) = 0;
      }
      if ((*(int *)(iVar2 + 0xc) != 0) && (iVar4 != *(int *)(iVar2 + 0xc))) {
        (*(code *)PTR_BIO_free_all_006a7f74)();
      }
      iVar5 = *(int *)(iVar2 + 0x10);
      if (((iVar5 != 0) && (iVar4 != iVar5)) && (iVar5 != *(int *)(iVar2 + 0xc))) {
        (*(code *)PTR_BIO_free_all_006a7f74)();
      }
      *(int *)(iVar2 + 0xc) = iVar4;
      *(int *)(iVar2 + 0x10) = iVar4;
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc0,7,"ssl_lib.c",0x2a1);
    return 0;
  }
  return iStack_38;
}

