using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitCamera : MonoBehaviour
{
	public Camera playerCamera;
	public Transform cameraFocus;
	public float xSensitivity = 1;
	public float ySensitivity = -1;
	public float moveSentivity = 1;
	private Vector3 playerChange;
	private float xLook;
	private float yLook;
	private float xMove;
	private float zMove;
	private float rotateSpeed;
	private float moveSpeed;
	public bool mouseLock = true;
	private bool rotateCamera = false;
	private float yRotationDif = 0;
	private float scrollPosition;

	void Start()
	{
		scrollPosition = 1;
		transform.position = cameraFocus.position - (cameraFocus.position - new Vector3(cameraFocus.transform.position.x, cameraFocus.transform.position.y + 1f, cameraFocus.transform.position.z - 1f)).normalized * 10 / scrollPosition;
		cameraFocus.LookAt(Camera.main.transform);
		playerCamera.transform.Rotate(Vector3.right, 45);
		playerChange = cameraFocus.transform.position;
		rotateSpeed = 20f;
		//transform.RotateAround(cameraFocus.transform.position, Vector3.up, 180);
		yRotationDif = transform.rotation.eulerAngles.y - yRotationDif;
		cameraFocus.transform.Rotate(Vector3.up, yRotationDif);
		yRotationDif = transform.rotation.eulerAngles.y;
	}

	void Update()
	{
		if (Input.GetKeyUp(KeyCode.Escape) || Input.GetKeyUp(KeyCode.LeftAlt))
		{
			mouseLock = !mouseLock;
		}

		//camera move input
		
		if (Input.GetMouseButton(1))
		{
			if (Input.GetMouseButtonDown(1))
			{
				Cursor.visible = false;
				rotateCamera = true;
				Cursor.lockState = CursorLockMode.Confined;
			}
			xLook = xSensitivity * Input.GetAxis("Mouse X");
			yLook = ySensitivity * Input.GetAxis("Mouse Y");
		}
		else if (Input.GetMouseButtonUp(1))
		{
			Cursor.visible = true;
			rotateCamera = false;
			Cursor.lockState = CursorLockMode.None;
			xLook = 0;
			yLook = 0;
		}

		if (Input.GetKey(KeyCode.LeftShift))
			moveSpeed = 2;
		else
			moveSpeed = 5;

		xMove = 0;
		zMove = 0;

		if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow))
		{
			zMove -= 1;
		}
		if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
		{
			xMove += 1;
		}
		if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
		{
			zMove += 1;
		}
		if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
		{
			xMove -= 1;
		}

		Vector3 clampedMove = Vector3.ClampMagnitude(new Vector3(xMove, 0, zMove), 1);
		xMove = clampedMove.x;
		zMove = clampedMove.z;

		scrollPosition += Input.GetAxis("Mouse ScrollWheel");
		if (scrollPosition < 1)
			scrollPosition = 1;
		else if (scrollPosition > 25)
			scrollPosition = 25;

		playerCamera.transform.eulerAngles = new Vector3(playerCamera.transform.eulerAngles.x, playerCamera.transform.eulerAngles.y, 0.0f);
		cameraFocus.LookAt(Camera.main.transform);
		cameraFocus.transform.eulerAngles = new Vector3(0.0f, cameraFocus.transform.eulerAngles.y, 0.0f);
	}

	void FixedUpdate()
	{
		if (xMove > 0)
			cameraFocus.transform.position += cameraFocus.transform.right / moveSpeed;
		else if(xMove < 0)
			cameraFocus.transform.position -= cameraFocus.transform.right / moveSpeed;
		if (zMove > 0)
			cameraFocus.transform.position += cameraFocus.transform.forward / moveSpeed;
		else if (zMove < 0)
			cameraFocus.transform.position -= cameraFocus.transform.forward / moveSpeed;

		//camera movement
		playerChange = cameraFocus.transform.position - playerChange;
		//playerChange.y = 0;
		transform.position += playerChange;

		//camera y rotation //IF ROTATION GETS WEIRD REORDER X AND Y!!!
		transform.RotateAround(cameraFocus.transform.position, Vector3.up, xLook * Time.deltaTime * rotateSpeed);
		yRotationDif = transform.rotation.eulerAngles.y - yRotationDif;
		cameraFocus.transform.Rotate(Vector3.up, yRotationDif);
		yRotationDif = transform.rotation.eulerAngles.y;

		//camera x rotation //DO NOT REORDER X AND Y!!!
		float xRotation = playerCamera.transform.rotation.eulerAngles.x;
		float futureRotation = yLook * Time.deltaTime * rotateSpeed;
		playerCamera.transform.RotateAround(cameraFocus.position, cameraFocus.right, futureRotation * -1f);
		if ((xRotation + futureRotation) >= 89 && (xRotation + futureRotation) <= 324)
		{
			playerCamera.transform.RotateAround(cameraFocus.position, cameraFocus.right, futureRotation * 1f);
		}

		//update player position
		playerChange = cameraFocus.position;
	}
}
