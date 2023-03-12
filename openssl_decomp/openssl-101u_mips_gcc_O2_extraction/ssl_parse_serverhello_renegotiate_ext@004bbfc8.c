
int ssl_parse_serverhello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
  uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415);
  uVar7 = uVar6 + uVar2;
  if (uVar7 != 0) {
    if (uVar6 == 0) {
      OpenSSLDie("t1_reneg.c",0xf0,"!expected_len || s->s3->previous_client_finished_len");
      if (*(char *)(*(int *)(param_1 + 0x58) + 0x415) != '\0') goto LAB_004bc024;
    }
    else if (uVar2 != 0) goto LAB_004bc024;
    OpenSSLDie("t1_reneg.c",0xf1,"!expected_len || s->s3->previous_server_finished_len");
  }
LAB_004bc024:
  if (param_3 < 1) {
    uVar5 = 0xf6;
  }
  else {
    if (param_3 == *param_2 + 1) {
      if (uVar7 == *param_2) {
        iVar8 = *(int *)(param_1 + 0x58);
        bVar1 = *(byte *)(iVar8 + 0x3d4);
        iVar3 = (*(code *)PTR_memcmp_006a9ad0)(param_2 + 1,iVar8 + 0x394,(uint)bVar1);
        if (iVar3 == 0) {
          iVar4 = (*(code *)PTR_memcmp_006a9ad0)
                            (param_2 + 1 + bVar1,iVar8 + 0x3d5,*(undefined *)(iVar8 + 0x415));
          if (iVar4 == 0) {
            iVar3 = 1;
            *(undefined4 *)(iVar8 + 0x418) = 1;
          }
          else {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x12d,0x151,"t1_reneg.c",0x119);
            *param_4 = 0x2f;
          }
          return iVar3;
        }
        uVar5 = 0x110;
      }
      else {
        uVar5 = 0x108;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x12d,0x151,"t1_reneg.c",uVar5);
      *param_4 = 0x28;
      return 0;
    }
    uVar5 = 0x100;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x12d,0x150,"t1_reneg.c",uVar5);
  *param_4 = 0x2f;
  return 0;
}

