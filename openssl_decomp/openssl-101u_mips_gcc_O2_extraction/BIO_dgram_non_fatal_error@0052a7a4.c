
int BIO_dgram_non_fatal_error(int error)

{
  if (error == 0x47) {
    return 1;
  }
  if (error < 0x48) {
    if (error == 4) {
      return 1;
    }
    if (error == 0xb) {
      return 1;
    }
  }
  else if (error - 0x95U < 2) {
    return 1;
  }
  return 0;
}

