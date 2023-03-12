
/* WARNING: Type propagation algorithm not settling */

int conn_state(BIO *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  byte *pbVar7;
  code *pcVar8;
  int iVar9;
  uint local_2c [2];
  
  pcVar8 = (code *)param_2[10];
  iVar9 = -1;
LAB_0009e91a:
  uVar6 = *param_2;
LAB_0009e91c:
  switch(uVar6) {
  case 1:
    pbVar7 = (byte *)param_2[1];
    if (pbVar7 == (byte *)0x0) {
      ERR_put_error(0x20,0x73,0x70,"bss_conn.c",0x8b);
      goto switchD_0009e922_caseD_8;
    }
    bVar2 = *pbVar7;
    while (local_2c[0] = (uint)bVar2, local_2c[0] != 0) {
      if (local_2c[0] == 0x3a || local_2c[0] == 0x2f) {
        if ((local_2c[0] == 0x3a || local_2c[0] == 0x2f) && (*pbVar7 = 0, local_2c[0] == 0x3a)) {
          bVar2 = pbVar7[1];
          pbVar1 = pbVar7 + 1;
          goto joined_r0x0009ead0;
        }
        pcVar4 = (char *)param_2[2];
        goto LAB_0009eab4;
      }
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar7;
    }
    local_2c[0] = 0;
    pcVar4 = (char *)param_2[2];
    goto LAB_0009eab4;
  case 2:
    iVar3 = BIO_get_host_ip((char *)param_2[1],(uchar *)(param_2 + 4));
    if (iVar3 < 1) goto switchD_0009e922_caseD_8;
    *param_2 = 3;
    uVar6 = 3;
    break;
  case 3:
    if (((char *)param_2[2] == (char *)0x0) ||
       (iVar3 = BIO_get_port((char *)param_2[2],(ushort *)(param_2 + 5)), iVar3 < 1))
    goto switchD_0009e922_caseD_8;
    *param_2 = 4;
    uVar6 = 4;
    break;
  case 4:
    memset((sockaddr *)(param_2 + 6),0,0x10);
    *(undefined2 *)(param_2 + 6) = 2;
    *(ushort *)((int)param_2 + 0x1a) =
         (ushort)(byte)((uint)*(ushort *)(param_2 + 5) >> 8) | *(ushort *)(param_2 + 5) << 8;
    param_2[7] = (uint)*(byte *)((int)param_2 + 0x13) << 0x18 |
                 (uint)*(byte *)((int)param_2 + 0x12) << 0x10 |
                 (uint)*(byte *)((int)param_2 + 0x11) << 8 | (uint)*(byte *)(param_2 + 4);
    *param_2 = 4;
    iVar9 = socket(2,1,6);
    if (iVar9 == -1) {
      piVar5 = __errno_location();
      ERR_put_error(2,4,*piVar5,"bss_conn.c",200);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x76,"bss_conn.c",0xcb);
      goto switchD_0009e922_caseD_8;
    }
    uVar6 = 8;
    param_1->num = iVar9;
    *param_2 = 8;
    break;
  case 5:
    BIO_clear_flags(param_1,0xf);
    iVar9 = connect(param_1->num,(sockaddr *)(param_2 + 6),0x10);
    param_1->retry_reason = 0;
    if (iVar9 < 0) {
      iVar3 = BIO_sock_should_retry(iVar9);
      if (iVar3 == 0) {
        piVar5 = __errno_location();
        ERR_put_error(2,2,*piVar5,"bss_conn.c",0xf6);
        ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
        ERR_put_error(0x20,0x73,0x67,"bss_conn.c",0xf9);
      }
      else {
        BIO_set_flags(param_1,0xc);
        *param_2 = 7;
        param_1->retry_reason = 2;
      }
      goto switchD_0009e922_caseD_8;
    }
    goto LAB_0009e99e;
  case 6:
    iVar9 = 1;
    goto switchD_0009e922_caseD_8;
  case 7:
    local_2c[0] = BIO_sock_error(param_1->num);
    if (local_2c[0] != 0) {
      BIO_clear_flags(param_1,0xf);
      ERR_put_error(2,2,local_2c[0],"bss_conn.c",0x104);
      iVar9 = 0;
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x6e,"bss_conn.c",0x107);
      goto switchD_0009e922_caseD_8;
    }
LAB_0009e99e:
    *param_2 = 6;
    uVar6 = 6;
    break;
  case 8:
    if ((param_2[3] != 0) && (iVar3 = BIO_socket_nbio(param_1->num,1), iVar3 == 0)) {
      ERR_put_error(0x20,0x73,0x68,"bss_conn.c",0xd5);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      goto switchD_0009e922_caseD_8;
    }
    iVar3 = param_1->num;
    local_2c[0] = 1;
    *param_2 = 5;
    local_2c[0] = setsockopt(iVar3,1,9,local_2c,4);
    if ((int)local_2c[0] < 0) {
      piVar5 = __errno_location();
      ERR_put_error(2,4,*piVar5,"bss_conn.c",0xe2);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x6d,"bss_conn.c",0xe5);
      goto switchD_0009e922_caseD_8;
    }
    uVar6 = *param_2;
    break;
  default:
    goto switchD_0009e922_caseD_8;
  }
  goto joined_r0x0009e980;
joined_r0x0009ead0:
  if (bVar2 == 0) goto LAB_0009eae8;
  if (bVar2 == 0x2f) {
    *pbVar1 = 0;
    goto LAB_0009eae8;
  }
  pbVar1 = (byte *)((int)pbVar1 + 1);
  bVar2 = *pbVar1;
  goto joined_r0x0009ead0;
LAB_0009eae8:
  if ((void *)param_2[2] != (void *)0x0) {
    CRYPTO_free((void *)param_2[2]);
  }
  pcVar4 = BUF_strdup((char *)(pbVar7 + 1));
  param_2[2] = pcVar4;
LAB_0009eab4:
  if (pcVar4 == (char *)0x0) {
    ERR_put_error(0x20,0x73,0x72,"bss_conn.c",0xa4);
    ERR_add_error_data(2,"host=",param_2[1]);
switchD_0009e922_caseD_8:
    if (pcVar8 != (code *)0x0) {
      iVar9 = (*pcVar8)(param_1,*param_2,iVar9);
      return iVar9;
    }
    return iVar9;
  }
  *param_2 = 2;
  uVar6 = 2;
joined_r0x0009e980:
  if (pcVar8 != (code *)0x0) goto LAB_0009e982;
  goto LAB_0009e91c;
LAB_0009e982:
  iVar9 = (*pcVar8)(param_1,uVar6,iVar9);
  if (iVar9 == 0) {
    return 0;
  }
  goto LAB_0009e91a;
}

