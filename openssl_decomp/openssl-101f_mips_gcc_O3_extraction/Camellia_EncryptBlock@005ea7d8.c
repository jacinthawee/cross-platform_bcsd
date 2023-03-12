
void Camellia_EncryptBlock(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0x80) {
    uVar1 = 3;
  }
  Camellia_EncryptBlock_Rounds(uVar1);
  return;
}

