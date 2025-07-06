function checkPalindrome() {
    const text = document.getElementById("inputText").value;
    const cleaned = text.toLowerCase().replace(/[^a-z0-9]/g, '');
    const reversed = cleaned.split('').reverse().join('');
    const isPalindrome = cleaned === reversed;

    const result = document.getElementById("result");
    result.textContent = isPalindrome
        ? "✅ It's a palindrome!"
        : "❌ Not a palindrome.";
}
