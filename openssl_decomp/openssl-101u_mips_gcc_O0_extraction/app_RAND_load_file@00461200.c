
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int app_RAND_load_file(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined auStack_e4 [200];
  char *local_1c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(char **)PTR___stack_chk_guard_006a9ae8;
  if (param_1 == 0) {
    iVar7 = (*(code *)PTR_RAND_file_name_006a7c6c)(auStack_e4,200);
    if (iVar7 != 0) goto LAB_0046129c;
LAB_004612b4:
    iVar7 = (*(code *)PTR_RAND_status_006a773c)();
    if (iVar7 == 0) {
      if (param_3 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_2,"unable to load \'random state\'\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (param_2,"This means that the random number generator has not been seeded\n");
        (*(code *)PTR_BIO_printf_006a6e38)(param_2,"with much random data.\n");
        if (param_1 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (param_2,
                     "Consider setting the RANDFILE environment variable to point at a file that\n")
          ;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (param_2,"\'random\' data can be kept in (the file will be overwritten).\n");
        }
      }
      goto LAB_00461268;
    }
  }
  else {
    iVar4 = (*(code *)PTR_RAND_egd_006a7c64)();
    iVar7 = param_1;
    if (0 < iVar4) {
      iVar7 = 1;
      egdsocket = 1;
      goto LAB_00461268;
    }
LAB_0046129c:
    iVar7 = (*(code *)PTR_RAND_load_file_006a7c68)(iVar7,0xffffffff);
    if (iVar7 == 0) goto LAB_004612b4;
  }
  iVar7 = 1;
  seeded = 1;
LAB_00461268:
  if (local_1c == *(char **)puVar3) {
    return iVar7;
  }
  pcVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = 0;
  cVar1 = *pcVar6;
  do {
    pcVar5 = pcVar6;
    if (cVar1 == '\0') {
      *pcVar6 = '\0';
      cVar1 = *pcVar6;
      bVar2 = true;
    }
    else {
      if (cVar1 == ':') {
        bVar2 = false;
      }
      else {
        do {
          pcVar5 = pcVar5 + 1;
          bVar2 = true;
          if (*pcVar5 == '\0') break;
          bVar2 = false;
        } while (*pcVar5 != ':');
      }
      *pcVar5 = '\0';
      cVar1 = *pcVar6;
    }
    if (cVar1 == '\0') {
LAB_00461450:
      if (0x200 < iVar7) {
        seeded = 1;
      }
      return iVar7;
    }
    iVar4 = (*(code *)PTR_RAND_egd_006a7c64)(pcVar6);
    if (iVar4 < 1) {
      iVar4 = (*(code *)PTR_RAND_load_file_006a7c68)(pcVar6,0xffffffff);
    }
    iVar7 = iVar7 + iVar4;
    if (bVar2) goto LAB_00461450;
    cVar1 = pcVar5[1];
    pcVar6 = pcVar5 + 1;
  } while( true );
}

