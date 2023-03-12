
int ssl_parse_serverhello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar5 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
  uVar4 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415);
  uVar7 = uVar5 + uVar4;
  if (uVar7 != 0) {
    if (uVar5 == 0) {
      OpenSSLDie("t1_reneg.c",0xf0,"!expected_len || s->s3->previous_client_finished_len");
      if (*(char *)(*(int *)(param_1 + 0x58) + 0x415) != '\0') goto LAB_0006b7e6;
    }
    else if (uVar4 != 0) goto LAB_0006b7e6;
    OpenSSLDie("t1_reneg.c",0xf1,"!expected_len || s->s3->previous_server_finished_len");
  }
LAB_0006b7e6:
  if (param_3 < 1) {
    iVar3 = 0xf6;
  }
  else {
    if (*param_2 + 1 == param_3) {
      if (*param_2 == uVar7) {
        iVar6 = *(int *)(param_1 + 0x58);
        bVar1 = *(byte *)(iVar6 + 0x3d4);
        iVar3 = memcmp(param_2 + 1,(void *)(iVar6 + 0x394),(uint)bVar1);
        if (iVar3 == 0) {
          iVar2 = memcmp(param_2 + 1 + bVar1,(void *)(iVar6 + 0x3d5),(uint)*(byte *)(iVar6 + 0x415))
          ;
          if (iVar2 == 0) {
            iVar3 = 1;
            *(undefined4 *)(iVar6 + 0x418) = 1;
          }
          else {
            ERR_put_error(0x14,0x12d,0x151,"t1_reneg.c",0x119);
            *param_4 = 0x2f;
          }
        }
        else {
          iVar3 = 0;
          ERR_put_error(0x14,0x12d,0x151,"t1_reneg.c",0x110);
          *param_4 = 0x28;
        }
        return iVar3;
      }
      ERR_put_error(0x14,0x12d,0x151,"t1_reneg.c",0x108);
      *param_4 = 0x28;
      return 0;
    }
    iVar3 = 0x100;
  }
  ERR_put_error(0x14,0x12d,0x150,"t1_reneg.c",iVar3);
  *param_4 = 0x2f;
  return 0;
}

