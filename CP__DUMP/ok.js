const https = require('https');

function countAgesOver50(input) {
    const items = input.split(',');
    let count = 0;

    items.forEach(item => {
        let parts = item.trim().split('=');
        if (parts[0].includes('age') && parseInt(parts[1]) >= 50) {
            count++;
        }
    });

    return count.toString();
}

function intersperseStrings(str1, str2) {
    let result = '';
    let maxLength = Math.max(str1.length, str2.length);

    for (let i = 0; i < maxLength; i++) {
        if (i < str1.length) {
            result += str1[i];
        }
        if (i < str2.length) {
            result += str2[i];
        }
    }

    return result;
}

https.get('https://coderbyte.com/api/challenges/json/age-counting', (resp) => {
    let data = '';

    resp.on('data', (chunk) => {
        data += chunk;
    });

    resp.on('end', () => {
        try {
            const parsedData = JSON.parse(data);

            let count = countAgesOver50(parsedData.data);

            let token = "2bf2nrcj93e0";

            let ans = intersperseStrings(count, token);

            console.log(ans);

        } catch (e) {
            console.error('Error parsing JSON:', e);
        }
    });

}).on('error', (error) => {
    console.error('Error:', error);
});
