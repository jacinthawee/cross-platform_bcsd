
int ssl3_get_server_done(int param_1)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x1160,0x1161,0xe,0x1e,&local_14);
  iVar2 = iVar1;
  if ((local_14 != 0) && (iVar2 = 1, 0 < iVar1)) {
    ssl3_send_alert(param_1,2,0x32);
    ERR_put_error(0x14,0x91,0x9f,"s3_clnt.c",0x8a0);
    iVar2 = -1;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

