
bool send_bio_chars(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_BIO_write_006a6e14)();
    return param_3 == iVar1;
  }
  return true;
}

