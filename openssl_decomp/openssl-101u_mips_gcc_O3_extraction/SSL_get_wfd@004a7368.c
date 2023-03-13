
int SSL_get_wfd(SSL *s)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar6 = 0x100;
  local_10 = -1;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_BIO_find_type_006a8320)(s->wbio,0x100);
  if (iVar2 != 0) {
    uVar6 = 0x69;
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x69,0,&local_10);
  }
  if (local_c != *(int *)puVar1) {
    iVar2 = local_c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar3 = (*(code *)PTR_BIO_s_socket_006a8324)();
    iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    if (iVar4 != 0) {
      (*(code *)PTR_BIO_int_ctrl_006a785c)(iVar4,0x68,0,uVar6);
      iVar5 = *(int *)(iVar2 + 0x14);
      if ((iVar5 != 0) && (iVar5 == *(int *)(iVar2 + 0x10))) {
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar5 + 0x24);
        *(undefined4 *)(iVar5 + 0x24) = 0;
      }
      if ((*(int *)(iVar2 + 0xc) != 0) && (iVar4 != *(int *)(iVar2 + 0xc))) {
        (*(code *)PTR_BIO_free_all_006a6e74)();
      }
      iVar5 = *(int *)(iVar2 + 0x10);
      if (((iVar5 != 0) && (iVar4 != iVar5)) && (iVar5 != *(int *)(iVar2 + 0xc))) {
        (*(code *)PTR_BIO_free_all_006a6e74)();
      }
      *(int *)(iVar2 + 0xc) = iVar4;
      *(int *)(iVar2 + 0x10) = iVar4;
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc0,7,"ssl_lib.c",0x2ac);
    return 0;
  }
  return local_10;
}

