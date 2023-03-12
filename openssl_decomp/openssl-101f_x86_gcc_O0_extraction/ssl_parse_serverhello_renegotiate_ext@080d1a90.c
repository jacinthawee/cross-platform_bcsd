
int ssl_parse_serverhello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
  bVar2 = *(byte *)(*(int *)(param_1 + 0x58) + 0x415);
  uVar5 = (uint)bVar1 + (uint)bVar2;
  if (uVar5 != 0) {
    if (bVar1 == 0) {
      OpenSSLDie("t1_reneg.c",0xf0,"!expected_len || s->s3->previous_client_finished_len");
      bVar2 = *(byte *)(*(int *)(param_1 + 0x58) + 0x415);
    }
    if (bVar2 == 0) {
      OpenSSLDie("t1_reneg.c",0xf1,"!expected_len || s->s3->previous_server_finished_len");
    }
  }
  if (param_3 < 1) {
    iVar6 = 0xf6;
  }
  else {
    if (param_3 == *param_2 + 1) {
      if (uVar5 == *param_2) {
        iVar6 = *(int *)(param_1 + 0x58);
        bVar1 = *(byte *)(iVar6 + 0x3d4);
        iVar3 = memcmp(param_2 + 1,(void *)(iVar6 + 0x394),(uint)bVar1);
        if (iVar3 == 0) {
          iVar4 = memcmp(param_2 + 1 + bVar1,(void *)(iVar6 + 0x3d5),(uint)*(byte *)(iVar6 + 0x415))
          ;
          if (iVar4 == 0) {
            *(undefined4 *)(iVar6 + 0x418) = 1;
            iVar3 = 1;
          }
          else {
            ERR_put_error(0x14,0x12d,0x151,"t1_reneg.c",0x119);
            *param_4 = 0x2f;
          }
          return iVar3;
        }
        iVar6 = 0x110;
      }
      else {
        iVar6 = 0x108;
      }
      ERR_put_error(0x14,0x12d,0x151,"t1_reneg.c",iVar6);
      *param_4 = 0x28;
      return 0;
    }
    iVar6 = 0x100;
  }
  ERR_put_error(0x14,0x12d,0x150,"t1_reneg.c",iVar6);
  *param_4 = 0x2f;
  return 0;
}

