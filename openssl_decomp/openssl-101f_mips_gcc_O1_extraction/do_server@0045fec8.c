
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ** do_server(undefined2 param_1,int *param_2,int **param_3,undefined4 *param_4,char *param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int **ppiVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined1 *unaff_s4;
  undefined4 *unaff_s5;
  code *pcVar9;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  int iStack_a4;
  undefined1 *puStack_9c;
  int iStack_98;
  int iStack_94;
  int **ppiStack_90;
  undefined1 *puStack_8c;
  undefined4 *puStack_88;
  code *pcStack_84;
  undefined4 local_70;
  undefined *local_68;
  undefined4 *local_5c;
  int local_58;
  int *local_54;
  undefined4 local_50;
  char *local_4c;
  undefined4 *local_48;
  char *local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  local_3c = 2;
  local_54 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_9c = (undefined1 *)&local_3c;
  local_68 = &_gp;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar8 = &DAT_00000011;
  local_5c = param_4;
  local_3a = param_1;
  if (param_2 == (int *)&SUB_00000002) {
    pcVar8 = &DAT_00000006;
    piVar7 = param_2;
    iStack_98 = (*(code *)PTR_socket_006aaa90)(2);
  }
  else {
    piVar7 = (int *)0x1;
    iStack_98 = (*(code *)PTR_socket_006aaa90)(2);
  }
  iStack_94 = -1;
  if (iStack_98 == -1) {
LAB_004600c0:
    ppiVar4 = (int **)0x0;
  }
  else {
    unaff_s5 = &local_40;
    local_70 = 4;
    local_40 = 1;
    param_4 = unaff_s5;
    (**(code **)(local_68 + -0x52ac))(iStack_98,0xffff,4);
    pcVar8 = &SUB_00000010;
    iVar3 = (**(code **)(local_68 + -0x53c4))(iStack_98,puStack_9c);
    if (iVar3 == -1) {
      (**(code **)(local_68 + -0x5358))(&DAT_00641540);
LAB_0046009c:
      pcVar9 = *(code **)(local_68 + -0x5474);
LAB_004600a0:
      piVar7 = (int *)0x0;
      (*pcVar9)(iStack_98);
      (**(code **)(local_68 + -0x5484))(iStack_98);
      goto LAB_004600c0;
    }
    if (param_2 == (int *)&SUB_00000002) {
      iVar3 = (**(code **)(local_68 + -0x5424))(iStack_98,0x80);
      if (iVar3 == -1) {
        pcVar9 = *(code **)(local_68 + -0x5474);
        goto LAB_004600a0;
      }
    }
    local_48 = *(undefined4 **)(local_68 + -0x7fa4);
    if (param_3 != (int **)0x0) {
      *param_3 = (int *)iStack_98;
    }
    unaff_s4 = &_ITM_registerTMCloneTable;
    iStack_94 = 0;
    puStack_9c = from_18063;
    local_50 = 0x6aba14;
    local_4c = "s\n";
    local_44 = "bad gethostbyaddr\n";
    do {
      while (pcVar8 = param_5, param_2 != (int *)&SUB_00000002) {
        ppiVar4 = (int **)(*(code *)local_5c)(iStack_94,iStack_98);
        if (iStack_94 != 0) {
          (**(code **)(local_68 + -0x7f58))(iStack_94);
        }
        pcVar9 = *(code **)(local_68 + -0x5474);
        if ((int)ppiVar4 < 0) goto LAB_00460040;
      }
      param_3 = (int **)&SUB_00000010;
      iStack_94 = -1;
      while( true ) {
        from_18063._0_4_ = 0;
        from_18063._4_4_ = 0;
        from_18063._8_4_ = 0;
        from_18063._12_4_ = 0;
        local_40 = 0x10;
        iVar3 = (**(code **)(local_68 + -0x5360))(iStack_98,from_18063,unaff_s5);
        if (iVar3 != -1) break;
        param_4 = (undefined4 *)(**(code **)(local_68 + -0x53ec))();
        param_4 = (undefined4 *)*param_4;
        if (param_4 != (undefined4 *)&SUB_00000004) {
          pcVar8 = "errno=%d ";
          (**(code **)(local_68 + -0x5454))(**(undefined4 **)(local_68 + -0x52e0),1);
          (**(code **)(local_68 + -0x5358))("accept");
          goto LAB_0046009c;
        }
      }
      local_58 = iVar3;
      param_3 = (int **)(**(code **)(local_68 + -0x5324))(local_50,4,2);
      if (param_3 == (int **)0x0) {
        iStack_94 = 0;
        (**(code **)(local_68 + -0x7fa8))(*local_48,local_44);
        ppiVar4 = (int **)(*(code *)local_5c)(0,local_58);
      }
      else {
        iVar3 = (**(code **)(local_68 + -0x53b0))(*param_3);
        pcVar8 = (char *)0x1c2;
        iStack_94 = (**(code **)(local_68 + -0x7dd8))(iVar3 + 1,local_4c + 0x1568);
        if (iStack_94 == 0) {
          (**(code **)(local_68 + -0x5358))("OPENSSL_malloc");
          goto LAB_0046009c;
        }
        param_3 = (int **)*param_3;
        iVar3 = (**(code **)(local_68 + -0x53b0))(param_3);
        pcVar8 = (char *)(iVar3 + 1);
        (**(code **)(local_68 + -0x7e7c))(iStack_94,param_3);
        iVar3 = GetHostByName(iStack_94);
        if (iVar3 == 0) {
          (**(code **)(local_68 + -0x7fa8))
                    (**(undefined4 **)(local_68 + -0x7fa4),"gethostbyname failure\n");
          goto LAB_0046009c;
        }
        if (*(int *)(iVar3 + 8) != 2) {
          (**(code **)(local_68 + -0x7fa8))
                    (**(undefined4 **)(local_68 + -0x7fa4),"gethostbyname addr is not AF_INET\n");
          goto LAB_0046009c;
        }
        pcVar8 = param_5;
        ppiVar4 = (int **)(*(code *)local_5c)(iStack_94,local_58);
        (**(code **)(local_68 + -0x7f58))(iStack_94);
      }
      (**(code **)(local_68 + -0x5474))(local_58,2);
      (**(code **)(local_68 + -0x5484))(local_58);
    } while (-1 < (int)ppiVar4);
    pcVar9 = *(code **)(local_68 + -0x5474);
LAB_00460040:
    piVar7 = (int *)&SUB_00000002;
    (*pcVar9)(iStack_98);
    (**(code **)(local_68 + -0x5484))(iStack_98);
    param_3 = ppiVar4;
  }
  if (local_2c == *local_54) {
    return ppiVar4;
  }
  pcStack_84 = extract_host_port;
  iVar3 = local_2c;
  (**(code **)(local_68 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppiStack_90 = param_3;
  puStack_8c = unaff_s4;
  puStack_88 = unaff_s5;
  puVar5 = (undefined *)(*(code *)PTR_strchr_006aab34)();
  if (puVar5 == (undefined *)0x0) {
    ppiVar4 = (int **)0x0;
    pcVar8 = "no port defined\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    goto LAB_004604a0;
  }
  *puVar5 = 0;
  if (pcVar8 != (char *)0x0) {
    iVar6 = (*(code *)PTR___isoc99_sscanf_006aab10)
                      (iVar3,"%u.%u.%u.%u",&uStack_b4,&uStack_b0,&uStack_ac,&uStack_a8);
    if (iVar6 == 4) {
      if ((((0xff < uStack_b4) || (0xff < uStack_b0)) || (0xff < uStack_ac)) || (0xff < uStack_a8))
      {
        ppiVar4 = (int **)0x0;
        pcVar8 = "invalid IP address\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *pcVar8 = (char)uStack_b4;
      pcVar8[1] = (char)uStack_b0;
      pcVar8[2] = (char)uStack_ac;
      pcVar8[3] = (char)uStack_a8;
    }
    else {
      iVar6 = GetHostByName(iVar3);
      if (iVar6 == 0) {
        ppiVar4 = (int **)0x0;
        pcVar8 = "gethostbyname failure\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      if (*(short *)(iVar6 + 10) != 2) {
        ppiVar4 = (int **)0x0;
        pcVar8 = "gethostbyname addr is not AF_INET\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *pcVar8 = ***(char ***)(iVar6 + 0x10);
      pcVar8[1] = *(char *)(**(int **)(iVar6 + 0x10) + 1);
      pcVar8[2] = *(char *)(**(int **)(iVar6 + 0x10) + 2);
      pcVar8[3] = *(char *)(**(int **)(iVar6 + 0x10) + 3);
    }
  }
  puVar1 = PTR_strtol_006aaa68;
  if (piVar7 != (int *)0x0) {
    *piVar7 = iVar3;
  }
  puVar5 = puVar5 + 1;
  pcVar8 = (char *)0x0;
  ppiVar4 = (int **)(*(code *)puVar1)(puVar5,0,10);
  if (ppiVar4 == (int **)0x0) {
    pcVar8 = &DAT_00641588;
    iVar3 = (*(code *)PTR_getservbyname_006aaafc)(puVar5);
    if (iVar3 == 0) {
      pcVar8 = "getservbyname failure for %s\n";
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",puVar5);
      goto LAB_004604a0;
    }
    *(short *)param_4 = (short)*(undefined4 *)(iVar3 + 8);
  }
  else {
    *(short *)param_4 = (short)ppiVar4;
  }
  ppiVar4 = (int **)0x1;
LAB_004604a0:
  if (iStack_a4 == *(int *)puVar2) {
    return ppiVar4;
  }
  iVar3 = iStack_a4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppiVar4 = (int **)(*(code *)PTR_strtol_006aaa68)();
  if (ppiVar4 == (int **)0x0) {
    iVar6 = (*(code *)PTR_getservbyname_006aaafc)(iVar3,&DAT_00641588);
    if (iVar6 != 0) {
      *(short *)pcVar8 = (short)*(undefined4 *)(iVar6 + 8);
      return (int **)0x1;
    }
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",iVar3);
  }
  else {
    *(short *)pcVar8 = (short)ppiVar4;
    ppiVar4 = (int **)0x1;
  }
  return ppiVar4;
}

