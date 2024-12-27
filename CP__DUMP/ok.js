const base62Chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Base62 Encoding Function
function encodeBase62(num) {
    let encoded = '';
    while (num > 0) {
        const remainder = num % 62;
        encoded = base62Chars[remainder] + encoded;
        num = Math.floor(num / 62);
    }
    return encoded || '0';
}

for(let i=0; i<100; i++){
    console.log(encodeBase62(i));
}
