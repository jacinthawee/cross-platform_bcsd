
int conn_state(BIO *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  code *pcVar9;
  int i;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  i = -1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar9 = (code *)param_2[10];
LAB_0052478c:
  uVar8 = *param_2;
LAB_00524790:
  switch(uVar8) {
  case 1:
    pcVar7 = (char *)param_2[1];
    if (pcVar7 != (char *)0x0) {
      cVar1 = *pcVar7;
      while (cVar1 != '\0') {
        if (cVar1 == ':') {
          local_30 = 0x3a;
LAB_00524a6c:
          *pcVar7 = '\0';
          if (local_30 == 0x3a) {
            cVar1 = pcVar7[1];
            pcVar5 = pcVar7 + 1;
            goto joined_r0x00524a98;
          }
          pcVar7 = (char *)param_2[2];
          goto LAB_00524924;
        }
        if (cVar1 == '/') {
          local_30 = 0x2f;
          goto LAB_00524a6c;
        }
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
      }
      pcVar7 = (char *)param_2[2];
      local_30 = 0;
      goto LAB_00524924;
    }
    ERR_put_error(0x20,0x73,0x70,"bss_conn.c",0x92);
  default:
switchD_005247a4_caseD_0:
    while( true ) {
      if (pcVar9 != (code *)0x0) {
        i = (*pcVar9)(param_1,*param_2,i);
      }
LAB_0052483c:
      if (local_2c == *(int *)puVar3) break;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
switchD_005247a4_caseD_6:
      i = 1;
    }
    return i;
  case 2:
    goto switchD_005247a4_caseD_2;
  case 3:
    goto switchD_005247a4_caseD_3;
  case 4:
    goto switchD_005247a4_caseD_4;
  case 5:
    BIO_clear_flags(param_1,0xf);
    i = (*(code *)PTR_connect_006aaa60)(param_1->num,param_2 + 6,0x10);
    param_1->retry_reason = 0;
    if (i < 0) {
      iVar4 = BIO_sock_should_retry(i);
      if (iVar4 == 0) {
        piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
        ERR_put_error(2,2,*piVar6,"bss_conn.c",0x10d);
        ERR_add_error_data(4,s_host__00667e8c,param_2[1],":",param_2[2]);
        ERR_put_error(0x20,0x73,0x67,"bss_conn.c",0x111);
      }
      else {
        BIO_set_flags(param_1,0xc);
        *param_2 = 7;
        param_1->retry_reason = 2;
      }
      goto switchD_005247a4_caseD_0;
    }
    break;
  case 6:
    goto switchD_005247a4_caseD_6;
  case 7:
    local_30 = BIO_sock_error(param_1->num);
    if (local_30 != 0) {
      BIO_clear_flags(param_1,0xf);
      i = 0;
      ERR_put_error(2,2,local_30,"bss_conn.c",0x11e);
      ERR_add_error_data(4,s_host__00667e8c,param_2[1],":",param_2[2]);
      ERR_put_error(0x20,0x73,0x6e,"bss_conn.c",0x122);
      goto switchD_005247a4_caseD_0;
    }
    break;
  case 8:
    goto switchD_005247a4_caseD_8;
  }
  *param_2 = 6;
  if (pcVar9 == (code *)0x0) {
    i = 1;
    goto LAB_0052483c;
  }
  uVar8 = 6;
  goto LAB_005248a8;
joined_r0x00524a98:
  if (cVar1 == '\0') goto LAB_00524acc;
  if (cVar1 == '/') {
    *pcVar5 = '\0';
    goto LAB_00524acc;
  }
  pcVar5 = pcVar5 + 1;
  cVar1 = *pcVar5;
  goto joined_r0x00524a98;
LAB_00524acc:
  if (param_2[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  pcVar7 = BUF_strdup(pcVar7 + 1);
  param_2[2] = pcVar7;
LAB_00524924:
  if (pcVar7 == (char *)0x0) {
    ERR_put_error(0x20,0x73,0x72,"bss_conn.c",0xaf);
    ERR_add_error_data(2,s_host__00667e8c,param_2[1]);
    goto switchD_005247a4_caseD_0;
  }
  *param_2 = 2;
  if (pcVar9 != (code *)0x0) {
    uVar8 = 2;
    goto LAB_005248a8;
  }
switchD_005247a4_caseD_2:
  iVar4 = BIO_get_host_ip((char *)param_2[1],(uchar *)(param_2 + 4));
  if (iVar4 < 1) goto switchD_005247a4_caseD_0;
  *param_2 = 3;
  if (pcVar9 != (code *)0x0) {
    uVar8 = 3;
    goto LAB_005248a8;
  }
switchD_005247a4_caseD_3:
  if (((char *)param_2[2] == (char *)0x0) ||
     (iVar4 = BIO_get_port((char *)param_2[2],(ushort *)(param_2 + 5)), iVar4 < 1))
  goto switchD_005247a4_caseD_0;
  *param_2 = 4;
  if (pcVar9 != (code *)0x0) {
    uVar8 = 4;
    goto LAB_005248a8;
  }
switchD_005247a4_caseD_4:
  (*(code *)PTR_memset_006aab00)(param_2 + 6,0,0x10);
  *(undefined2 *)(param_2 + 6) = 2;
  param_2[7] = param_2[4];
  puVar2 = PTR_socket_006aaa90;
  *(undefined2 *)((int)param_2 + 0x1a) = *(undefined2 *)(param_2 + 5);
  *param_2 = 4;
  i = (*(code *)puVar2)(2,2,6);
  if (i == -1) {
    piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    ERR_put_error(2,4,*piVar6,"bss_conn.c",0xd7);
    ERR_add_error_data(4,s_host__00667e8c,param_2[1],":",param_2[2]);
    ERR_put_error(0x20,0x73,0x76,"bss_conn.c",0xda);
    goto switchD_005247a4_caseD_0;
  }
  param_1->num = i;
  *param_2 = 8;
  if (pcVar9 != (code *)0x0) {
    uVar8 = 8;
    goto LAB_005248a8;
  }
switchD_005247a4_caseD_8:
  if ((param_2[3] != 0) && (iVar4 = BIO_socket_nbio(param_1->num,1), iVar4 == 0)) {
    ERR_put_error(0x20,0x73,0x68,"bss_conn.c",0xe6);
    ERR_add_error_data(4,s_host__00667e8c,param_2[1],":",param_2[2]);
    goto switchD_005247a4_caseD_0;
  }
  puVar2 = PTR_setsockopt_006aac34;
  iVar4 = param_1->num;
  *param_2 = 5;
  local_30 = 1;
  local_30 = (*(code *)puVar2)(iVar4,0xffff,8,&local_30,4);
  if (local_30 < 0) {
    piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    ERR_put_error(2,4,*piVar6,"bss_conn.c",0xf4);
    ERR_add_error_data(4,s_host__00667e8c,param_2[1],":",param_2[2]);
    ERR_put_error(0x20,0x73,0x6d,"bss_conn.c",0xf7);
    goto switchD_005247a4_caseD_0;
  }
  uVar8 = *param_2;
  if (pcVar9 != (code *)0x0) goto LAB_005248a8;
  goto LAB_00524790;
LAB_005248a8:
  i = (*pcVar9)(param_1,uVar8,i);
  if (i == 0) goto LAB_0052483c;
  goto LAB_0052478c;
}

