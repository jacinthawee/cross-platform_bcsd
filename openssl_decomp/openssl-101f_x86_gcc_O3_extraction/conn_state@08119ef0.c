
/* WARNING: Removing unreachable block (ram,0x0811a227) */

int __regparm3 conn_state(BIO *param_1,undefined4 *param_2)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  int i;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  i = -1;
  pcVar2 = (code *)param_2[10];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
LAB_08119f1d:
  uVar3 = *param_2;
LAB_08119f1f:
  switch(uVar3) {
  case 1:
    pcVar6 = (char *)param_2[1];
    if (pcVar6 == (char *)0x0) {
      ERR_put_error(0x20,0x73,0x70,"bss_conn.c",0x92);
    }
    else {
      cVar1 = *pcVar6;
      local_24 = (int)cVar1;
      if (cVar1 == '\0') {
LAB_0811a04a:
        local_24 = 0;
LAB_0811a052:
        pcVar6 = (char *)param_2[2];
      }
      else {
        if ((cVar1 != '/') && (cVar1 != ':')) {
          do {
            pcVar6 = pcVar6 + 1;
            cVar1 = *pcVar6;
            local_24 = (int)cVar1;
            if (cVar1 == '\0') goto LAB_0811a04a;
          } while ((cVar1 != ':') && (cVar1 != '/'));
        }
        if (local_24 != 0x3a) {
          if (local_24 == 0x2f) {
            *pcVar6 = '\0';
          }
          goto LAB_0811a052;
        }
        *pcVar6 = '\0';
        cVar1 = pcVar6[1];
        pcVar5 = pcVar6 + 1;
        while (cVar1 != '\0') {
          if (cVar1 == '/') {
            *pcVar5 = '\0';
            break;
          }
          pcVar5 = pcVar5 + 1;
          cVar1 = *pcVar5;
        }
        if ((void *)param_2[2] != (void *)0x0) {
          CRYPTO_free((void *)param_2[2]);
        }
        pcVar6 = BUF_strdup(pcVar6 + 1);
        param_2[2] = pcVar6;
      }
      if (pcVar6 != (char *)0x0) {
        *param_2 = 2;
        if (pcVar2 == (code *)0x0) goto switchD_08119f24_caseD_2;
        uVar3 = 2;
        goto LAB_08119fed;
      }
      ERR_put_error(0x20,0x73,0x72,"bss_conn.c",0xaf);
      ERR_add_error_data(2,"host=",param_2[1]);
    }
    break;
  case 2:
switchD_08119f24_caseD_2:
    iVar4 = BIO_get_host_ip((char *)param_2[1],(uchar *)(param_2 + 4));
    if (0 < iVar4) {
      *param_2 = 3;
      if (pcVar2 == (code *)0x0) goto switchD_08119f24_caseD_3;
      uVar3 = 3;
      goto LAB_08119fed;
    }
    break;
  case 3:
switchD_08119f24_caseD_3:
    if (((char *)param_2[2] != (char *)0x0) &&
       (iVar4 = BIO_get_port((char *)param_2[2],(ushort *)(param_2 + 5)), 0 < iVar4)) {
      *param_2 = 4;
      if (pcVar2 == (code *)0x0) goto switchD_08119f24_caseD_4;
      uVar3 = 4;
      goto LAB_08119fed;
    }
    break;
  case 4:
switchD_08119f24_caseD_4:
    *(ushort *)((int)param_2 + 0x1a) = *(ushort *)(param_2 + 5) >> 8 | *(ushort *)(param_2 + 5) << 8
    ;
    param_2[8] = 0;
    param_2[9] = 0;
    *(undefined2 *)(param_2 + 6) = 2;
    param_2[7] = param_2[4];
    *param_2 = 4;
    i = socket(2,1,6);
    if (i != -1) {
      param_1->num = i;
      *param_2 = 8;
      if (pcVar2 == (code *)0x0) goto switchD_08119f24_caseD_8;
      uVar3 = 8;
      goto LAB_08119fed;
    }
    piVar7 = __errno_location();
    ERR_put_error(2,4,*piVar7,"bss_conn.c",0xd7);
    ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
    ERR_put_error(0x20,0x73,0x76,"bss_conn.c",0xda);
    break;
  case 5:
    BIO_clear_flags(param_1,0xf);
    i = connect(param_1->num,(sockaddr *)(param_2 + 6),0x10);
    param_1->retry_reason = 0;
    if (-1 < i) {
LAB_08119fda:
      *param_2 = 6;
      if (pcVar2 == (code *)0x0) {
        i = 1;
        goto LAB_08119fa2;
      }
      uVar3 = 6;
      goto LAB_08119fed;
    }
    iVar4 = BIO_sock_should_retry(i);
    if (iVar4 == 0) {
      piVar7 = __errno_location();
      ERR_put_error(2,2,*piVar7,"bss_conn.c",0x10d);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x67,"bss_conn.c",0x111);
    }
    else {
      BIO_set_flags(param_1,0xc);
      *param_2 = 7;
      param_1->retry_reason = 2;
    }
    break;
  case 6:
    i = 1;
    break;
  case 7:
    local_24 = BIO_sock_error(param_1->num);
    if (local_24 == 0) goto LAB_08119fda;
    i = 0;
    BIO_clear_flags(param_1,0xf);
    ERR_put_error(2,2,local_24,"bss_conn.c",0x11e);
    ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
    ERR_put_error(0x20,0x73,0x6e,"bss_conn.c",0x122);
    break;
  case 8:
switchD_08119f24_caseD_8:
    if ((param_2[3] != 0) && (iVar4 = BIO_socket_nbio(param_1->num,1), iVar4 == 0)) {
      ERR_put_error(0x20,0x73,0x68,"bss_conn.c",0xe6);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      break;
    }
    local_24 = 1;
    *param_2 = 5;
    local_24 = setsockopt(param_1->num,1,9,&local_24,4);
    if (local_24 < 0) {
      piVar7 = __errno_location();
      ERR_put_error(2,4,*piVar7,"bss_conn.c",0xf4);
      ERR_add_error_data(4,"host=",param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x6d,"bss_conn.c",0xf7);
      break;
    }
    uVar3 = *param_2;
    if (pcVar2 != (code *)0x0) goto LAB_08119fed;
    goto LAB_08119f1f;
  }
  if (pcVar2 != (code *)0x0) {
    i = (*pcVar2)(param_1,*param_2,i);
  }
  goto LAB_08119fa2;
LAB_08119fed:
  i = (*pcVar2)(param_1,uVar3,i);
  if (i == 0) {
LAB_08119fa2:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return i;
  }
  goto LAB_08119f1d;
}

