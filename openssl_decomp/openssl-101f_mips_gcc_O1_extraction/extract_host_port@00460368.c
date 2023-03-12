
int extract_host_port(undefined4 param_1,undefined4 *param_2,undefined *param_3,undefined2 *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar3 = (undefined *)(*(code *)PTR_strchr_006aab34)(param_1,0x3a);
  if (puVar3 == (undefined *)0x0) {
    iVar4 = 0;
    pcVar7 = "no port defined\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    goto LAB_004604a0;
  }
  *puVar3 = 0;
  if (param_3 != (undefined *)0x0) {
    iVar4 = (*(code *)PTR___isoc99_sscanf_006aab10)
                      (param_1,"%u.%u.%u.%u",&local_34,&local_30,&local_2c,&local_28);
    if (iVar4 == 4) {
      if ((((0xff < local_34) || (0xff < local_30)) || (0xff < local_2c)) || (0xff < local_28)) {
        iVar4 = 0;
        pcVar7 = "invalid IP address\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *param_3 = (char)local_34;
      param_3[1] = (char)local_30;
      param_3[2] = (char)local_2c;
      param_3[3] = (char)local_28;
    }
    else {
      iVar4 = GetHostByName(param_1);
      if (iVar4 == 0) {
        iVar4 = 0;
        pcVar7 = "gethostbyname failure\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      if (*(short *)(iVar4 + 10) != 2) {
        iVar4 = 0;
        pcVar7 = "gethostbyname addr is not AF_INET\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *param_3 = *(undefined *)**(undefined4 **)(iVar4 + 0x10);
      param_3[1] = *(undefined *)(**(int **)(iVar4 + 0x10) + 1);
      param_3[2] = *(undefined *)(**(int **)(iVar4 + 0x10) + 2);
      param_3[3] = *(undefined *)(**(int **)(iVar4 + 0x10) + 3);
    }
  }
  puVar1 = PTR_strtol_006aaa68;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  puVar3 = puVar3 + 1;
  pcVar7 = (char *)0x0;
  iVar4 = (*(code *)puVar1)(puVar3,0,10);
  if (iVar4 == 0) {
    pcVar7 = &DAT_00641588;
    iVar5 = (*(code *)PTR_getservbyname_006aaafc)(puVar3);
    if (iVar5 == 0) {
      pcVar7 = "getservbyname failure for %s\n";
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",puVar3);
      goto LAB_004604a0;
    }
    *param_4 = (short)*(undefined4 *)(iVar5 + 8);
  }
  else {
    *param_4 = (short)iVar4;
  }
  iVar4 = 1;
LAB_004604a0:
  if (local_24 == *(int *)puVar2) {
    return iVar4;
  }
  iVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_strtol_006aaa68)();
  if (iVar5 == 0) {
    iVar6 = (*(code *)PTR_getservbyname_006aaafc)(iVar4,&DAT_00641588);
    if (iVar6 != 0) {
      *(short *)pcVar7 = (short)*(undefined4 *)(iVar6 + 8);
      return 1;
    }
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",iVar4);
  }
  else {
    *(short *)pcVar7 = (short)iVar5;
    iVar5 = 1;
  }
  return iVar5;
}

